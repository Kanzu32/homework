#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <clocale>
#include <codecvt>
#include <sstream>

using namespace std;

//30 вариант
//24. Дан массив действительных чисел размера n. Выполнить циклический сдвиг элементов массива, находящихся на нечетных местах, влево.
void taskOne();

void taskTwo();
//Имеется текстовый файл и целое число k(-33 <= k <= 33).Создать новый файл, в который записать текст исходного файла, закодированный шифром Цезаря (шифруются только буквы русского алфавита).
void taskThree();

struct Human
{
	string name;
	double height;
};
bool increase(Human a, Human b) {
	return (a.height < b.height);
}
bool decrease(Human a, Human b) {
	return (a.height > b.height);
}
void sortByHeight(vector<Human> person, bool mode) {
	if (mode) {
		sort(person.begin(), person.end(), increase);
	}
	else {
		sort(person.begin(), person.end(), decrease);
	}
}

int main()
{
	int taskNumber;

	cin >> taskNumber;

	while (!cin.eof())
	{
		switch (taskNumber)
		{
		case 1:
			taskOne();
			cin >> taskNumber;
			break;

		case 2:
			taskTwo();
			cin >> taskNumber;
			break;

		case 3:
			taskThree();
			cin >> taskNumber;
			break;

		default:
			cout << "input error\n";
			cout << "ctrl + z for exit.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> taskNumber;
			break;
		}
	}
}

void shiftArray(double* &arr, int n) {
	double first;

	first = arr[0];

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0 && i + 2 < n) {
			arr[i] = arr[i + 2];
		}
		else if (i % 2 == 0) {
			arr[i] = first;
		}
	}
}

void readArrayFromFile(string fileName, double* &arr, int &n) {
	ifstream file;
	file.open(fileName + ".txt");
	file >> n;
	double tmp;
	arr = new double[n];
	for (int i = 0; i < n; i++) {
		file >> tmp;
		arr[i] = tmp;
	}
	file.close();
}

void writeArrayToFile(string fileName, double* arr, int n) {
	
	ofstream toTextFile(fileName + ".txt");
	int textBegin = toTextFile.tellp();
	ofstream toBinFile(fileName + ".data", ios::binary);
	int binBegin = toBinFile.tellp();
	for (int i = 0; i < n; i++) {
		toTextFile << arr[i] << " ";
	}
	toBinFile.write(reinterpret_cast<char*>(arr), n*sizeof(double));
	int textEnd = toTextFile.tellp();
	int binEnd = toBinFile.tellp();
	cout << "Text file size: " << (textEnd-textBegin) << '\n'
		<< "Binary file size: " << (binEnd-binBegin) << '\n';
	toTextFile.close();
	toBinFile.close();
}

void printArray(double *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void taskOne() {
	double* arr;
	int n;
	readArrayFromFile("in", arr, n);
	shiftArray(arr, n);
	writeArrayToFile("out", arr, n);
}


void printCommads() {
	cout << "Commands: read, write, add, del, sort, print, exit\n";
}

void printStructArray(vector<Human> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << "[" << (i+1) << "] " << arr[i].name << " " << arr[i].height << "\n";
	}
}

void sortStructArray(vector<Human> &arr) {
	bool mode;
	cout << "Sort (1 - increase, 0 - decrease): ";
	cin >> mode;
	if (mode) {
		sort(arr.begin(), arr.end(), increase);
	}
	else {
		sort(arr.begin(), arr.end(), decrease);
	}
}

void addHuman(vector<Human> &arr, Human human) {
	arr.push_back(human);
}

void delHuman(vector<Human> &arr, int n) {
	arr.erase(arr.begin() + n-1);
}

void readStructArrayFromFile(string fileName, vector<Human> &arr) {
	ifstream file;
	string name;
	double height;
	file.open(fileName + ".data");
	while (!file.eof()) {
		file >> name >> height;
		addHuman(arr, Human{name, height});
	}
	file.close();
}

void writeStructArrayToFile(string fileName, vector<Human> arr) {
	ofstream tofile(fileName + ".data");
	for (int i = 0; i < arr.size(); i++) {
		tofile << arr[i].name << " " << arr[i].height << '\n';
	}
	tofile.close();
}

void taskTwo() {
	vector <Human> arr;

	string command;
	printCommads();
	cin >> command;
	while (command != "exit") {
		if (command == "read") {
			string fileName;
			cout << "Enter file name: ";
			cin >> fileName;
			readStructArrayFromFile(fileName, arr);
			cout << "OK\n";
		}
		else if (command == "write") {
			string fileName;
			cout << "Enter file name: ";
			cin >> fileName;
			writeStructArrayToFile(fileName, arr);
			cout << "OK\n";
		}
		else if (command == "add") {
			string name;
			double height;
			cout << "Enter name and height: ";
			cin >> name >> height;
			addHuman(arr, Human{name, height});
			cout << "OK\n";
		}
		else if (command == "del") {
			int number;
			printStructArray(arr);
			cout << "Enter number of student: ";
			cin >> number;
			delHuman(arr, number);
			cout << "OK\n";
		}
		else if (command == "print") {
			printStructArray(arr);
		}
		else if (command == "sort") {
			sortStructArray(arr);
			cout << "OK\n";
		}
		else {
			cout << "unknown command.";
		} 
		printCommads();
		cin >> command;
	}

}

wstring readTextFromFile(string fileName) {
	wstring res;
	ifstream file;
	file.open(fileName+".txt");
	// char c;
	// while (!file.eof()) {
	// 	file.get(c);
	// 	res += c;
	// }
	string* arr[];
	file.read(reinterpret_cast<wchar_t>(arr), 100*sizeof(wchar_t));
}

void writeTextToFile(string fileName, string data) {
	ofstream tofile(fileName+".txt");
	tofile << data;
}

void encryptText(string &s, int k) {
	;
}

//int a1[] = {'А'}ж

void taskThree() {
	int k;
	//cout << "Enter k: ";
	//cin >> k;
	wstring s = readTextFromFile("text");
	wcout << s;
	//writeTextToFile("textOut", s);
}