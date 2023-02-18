#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

//Задача 1. Дан массив целых чисел размера n. Перед каждым значением,
//которое является числом Люка вставить ноль или сообщить, что таких
//элементов нет. 29. Дан массив целых чисел размера n. Перед первым
//минимальным элементом массива вставить все его делители.
//Задача 2. Дан текст на русском языке. Напечатать в алфавитном порядке
//все звонкие согласные буквы, которые входят более чем в одно слово.
//Задача 3. Разработать и согласовать с преподавателем набор функций
//(методов) для базового (или более высокого) уровня задания курсового
//проекта, использующих контейнеры map (или multimap).
//Задача 4. Дан вектор v. Найти сумму отрицательных и сумму
//положительных элементов вектора. Использовать два вызова алгоритма
//accumulate с параметрами — функциональными объектами.

void taskOne();
void fillArr(vector<int> &arr);
bool isL(int num);
void printVector(vector<int> arr);

void taskFour();
int sumPositive(int a, int b);
int sumNegative(int a, int b);

int main()
{
	int taskNumber;
    cout << "task: ";
	cin >> taskNumber;

	while (!cin.eof())
	{
		switch (taskNumber)
		{
		case 1:
			taskOne();
            cout << "task: ";
			cin >> taskNumber;
			break;

		case 4:
			taskFour();
            cout << "task: ";
			cin >> taskNumber;
			break;

		default:
			cout << "input error\n";
			cout << "ctrl + z for exit.\n";
			cin.clear();
			cin.ignore(1000, '\n');
            cout << "task: ";
			cin >> taskNumber;
			break;
		}
	}
}

void taskOne () {
    vector <int> arr;
    fillArr(arr);
    int i = 0;
    while (i < arr.size()) {
        if ( isL(arr.at(i)) ) {
            arr.insert(arr.begin()+i, 0);
            i += 2;
        } else {
            i++;
        }
    }
    printVector(arr);
}

void fillArr(vector<int> &arr) {
    int input;
    cout << "numbers: ";
    while (cin >> input)
        arr.push_back(input);
    cin.clear();
	cin.ignore(1000, '\n');
}

bool isL(int num) {
    for (int i = 1; i < 100; i++) {
        if (pow((1+sqrt(5))/2, i)+pow((1-sqrt(5))/2, i) == num) {
            return true;
        }
    }
    return false;
}

void printVector(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


void taskFour() {
    vector <int> arr;
    fillArr(arr);
    cout << "Positive: " << accumulate(arr.begin(), arr.end(), 0, sumPositive) << endl;
    cout << "Negative: " << accumulate(arr.begin(), arr.end(), 0, sumNegative) << endl;
}

int sumPositive(int a, int b) {
    if (b > 0) {
        return a+b;
    } else {
        return a;
    }
}

int sumNegative(int a, int b) {
    if (b < 0) {
        return a+b;
    } else {
        return a;
    }
}