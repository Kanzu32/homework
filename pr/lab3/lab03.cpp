#include <iostream>
#include <vector>
#include <ctime>
#include "minmax.h"
#include "minmax.cpp"
#include "svg.h"
#include "svg.cpp"

using namespace std;

const char GIST_CHAR = '*';
const size_t SCREEN_WIDTH = 80;
const size_t MAX_GIST_WIDTH = SCREEN_WIDTH - 3 - 1;
const auto RAND_SEED = time(0);
const bool SVG_OUTPUT = true;

vector<double> getNumbersArray(size_t numbersCount);
vector<double> generateNumbersArray(size_t numbersCount);
vector<size_t> getBinsDistribution(vector<double> numbers, size_t binCount);
void cmdOutput(vector<size_t> bins, size_t maxBinCount);
string formatLabel(size_t item);
string formatGist(size_t item, size_t maxBinCount);
size_t findMaxBinCount(vector<size_t> bins);
double getRandomNumber();

int main() {
    srand(RAND_SEED);
    size_t numbersCount;
    cerr << "Enter numbers count: ";
    cin >> numbersCount;

    vector<double> numbers;
    bool generate;
    cerr << "Generate random numbers? (1/0): ";
    cin >> generate;
    if (generate) {
        numbers = generateNumbersArray(numbersCount);
    } else {
        cerr << "Enter numbers: ";
        numbers = getNumbersArray(numbersCount);
    }

    size_t binCount;
    cerr << "Enter bins count: ";
    cin >> binCount;

    vector<size_t> bins = getBinsDistribution(numbers, binCount);
    size_t maxBinCount = findMaxBinCount(bins);

    if (SVG_OUTPUT) {
        svgOutput(bins, maxBinCount);
    } else {
        cmdOutput(bins, maxBinCount);
    }
}

vector<double> getNumbersArray(size_t numbersCount) {
    vector<double> res(numbersCount);
    for (int i = 0; i < numbersCount; i++) {
        cin >> res[i];
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

vector<size_t> getBinsDistribution(vector<double> numbers, size_t binCount) {
    vector<size_t> res(binCount);
    double minVal = 0;
    double maxVal = 0;
    findMinMax(numbers, minVal, maxVal);
    double step = (maxVal - minVal) / binCount;

    for (auto item : numbers) {
        bool found = false;
        for (size_t i = 0; (i < binCount-1) && !found; i++) {
            auto lo = minVal + i * step;
            auto hi = minVal + (i + 1) * step;
            if ((lo <= item) && (item < hi)) {
                res[i]++;
                found = true;
            }
        }
        if (!found) {
            res[binCount - 1]++;
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