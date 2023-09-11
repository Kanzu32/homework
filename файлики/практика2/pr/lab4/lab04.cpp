#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include "modules/minmax.h"
#include "modules/minmax.cpp"
#include "modules/svg.h"
#include "modules/svg.cpp"
#include "curl/include/curl/curl.h"

using namespace std;

const char GIST_CHAR = '*';
const size_t SCREEN_WIDTH = 80;
const size_t MAX_GIST_WIDTH = SCREEN_WIDTH - 3 - 1;
const auto RAND_SEED = time(0);
const bool SVG_OUTPUT = true;

struct Input {
    vector<double> numbers;
    size_t binCount;
};

Input getInput(istream& in, bool prompt);
vector<double> getNumbersArray(istream& in, size_t numbersCount);
vector<double> generateNumbersArray(size_t numbersCount);
vector<size_t> getBinsDistribution(Input& data);
void cmdOutput(vector<size_t> bins, size_t maxBinCount);
string formatLabel(size_t item);
string formatGist(size_t item, size_t maxBinCount);
size_t findMaxBinCount(vector<size_t> bins);
double getRandomNumber();
string getRandomColor();

void svgOutput(vector<size_t> bins, size_t maxBinCount);
void svgHeader(double width, double height);
void svgFooter();
void svgText(double x, double y, string text);
void svgRect(double x, double y, double width, double height, string color, double opacity);

size_t writeInBuffer(void* items, size_t itemSize, size_t itemCount, void* ctx);
Input download(const string& address);

int main(int argc, char* argv[]) {
    srand(RAND_SEED);
    Input data;

    if (argc > 1) {
        data = download(argv[1]);
    } else {
        data = getInput(cin, true);
    }
    cerr << data.binCount;
    vector<size_t> bins = getBinsDistribution(data);
    size_t maxBinCount = findMaxBinCount(bins);
    if (SVG_OUTPUT) {
        svgOutput(bins, maxBinCount);
    } else {
        cmdOutput(bins, maxBinCount);
    }
}

Input download(const string& address) {
    stringstream buffer;
    CURL* curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeInBuffer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
        res = curl_easy_perform(curl);
        if (res == CURLE_HTTP_RETURNED_ERROR) {
            cerr << "FAILED TO LOAD FILE" << endl;
        }
        if (res != CURLE_OK) {
            cerr << "ERROR " << res << ": " << curl_easy_strerror(res) << endl;
            exit(1);
        }
        curl_easy_cleanup(curl);
    }

    return getInput(buffer, false);
}

size_t writeInBuffer(void* items, size_t itemSize, size_t itemCount, void* ctx) {
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    const char* data = reinterpret_cast<char*>(items);
    size_t dataSize = itemCount * itemSize;
    buffer->write(data, dataSize);
    return dataSize;
}

Input getInput(istream& in, bool prompt) {
    Input data;

    size_t numbersCount;
    if (prompt) {cerr << "Enter numbers count: ";};
    in >> numbersCount;

    bool generate;
    if (prompt) {cerr << "Generate random numbers? (1/0): ";};
    in >> generate;
    if (generate) {
        data.numbers = generateNumbersArray(numbersCount);
    } else {
        cerr << "Enter numbers: ";
        data.numbers = getNumbersArray(in, numbersCount);
    }

    if (prompt) {cerr << "Enter bins count: ";};
    in >> data.binCount;

    return data;    
}

vector<double> getNumbersArray(istream& in, size_t numbersCount) {
    vector<double> res(numbersCount);
    for (int i = 0; i < numbersCount; i++) {
        in >> res[i];
    }
    return res;
}

vector<double> generateNumbersArray(size_t numbersCount) {
    vector<double> res(numbersCount);
    for (int i = 0; i < numbersCount; i++) {
        //res[i] = rand() % 101;
        res[i] = getRandomNumber();
    }
    return res;
}

vector<size_t> getBinsDistribution(Input& data) {
    vector<size_t> res(data.binCount);
    double minVal = 0;
    double maxVal = 0;
    findMinMax(data.numbers, minVal, maxVal);
    double step = (maxVal - minVal) / data.binCount;

    for (auto item : data.numbers) {
        bool found = false;
        for (size_t i = 0; (i < data.binCount-1) && !found; i++) {
            auto lo = minVal + i * step;
            auto hi = minVal + (i + 1) * step;
            if ((lo <= item) && (item < hi)) {
                res[i]++;
                found = true;
            }
        }
        if (!found) {
            res[data.binCount - 1]++;
        }
    }
    return res;
}

string formatLabel(size_t item) {
    string prefix = "";
    if (item / 10 == 0) {
        prefix = "  ";
    } else if (item / 100 == 0) {
        prefix = " ";
    }
    return prefix + to_string(item);
}

string formatGist(size_t item, size_t maxBinCount) {
    if (maxBinCount <= MAX_GIST_WIDTH) {
        return string(item, GIST_CHAR);
    }
    else {
        size_t height = MAX_GIST_WIDTH * (static_cast<double>(item) / maxBinCount);
        return string(height, GIST_CHAR);
    }
}

size_t findMaxBinCount(vector<size_t> bins) {
    size_t mx = 0;
    for (size_t item : bins) {
        if (item > mx) {
            mx = item;
        }
    }
    return mx;
}

double getRandomNumber() {
    double sm = 0;
    for (int i = 0; i < 12; i++) {
        sm += rand();
    }
    return sm;
}

void cmdOutput(vector<size_t> bins, size_t maxBinCount) {
    for (size_t item : bins) {
        cout << formatLabel(item) << "|" << formatGist(item, maxBinCount) << endl;
    }
}