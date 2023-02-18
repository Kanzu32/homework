#include <iostream>
#include <vector>
#include <iterator>

//Написать шаблонную функцию пузырьковой сортировки, параметрами которой являются два итератора и функтор для сравнения элементов (на которые указывают итераторы). С помощью описанной шаблонной функции отсортировать массив целых чисел и вектор дробных чисел. Обратите внимание, что 3-м параметром должен быть именно функтор, т.е. объект класса специального вида.

using namespace std;

template <typename T>
class F {
public:
    bool operator ()(T a, T b) {
        if (a > b) return true;
        else return false;
    };
};


template <typename Iter, typename Cmp>
void sort(Iter first, Iter last, Cmp cmp) {
    for (int x = 0; x < last-first; x++) {
        for (Iter i = first; i < last-x; i++) {
            if (cmp(*i, *(i+1))) {
                swap(*i, *(i+1));
            };
        }
    }
};

template <typename Iter>
void print(Iter first, Iter last) {
    for (Iter i = first; i <= last; i++) {
        cout << *i << " ";
    }
    cout << "\n=============================" << endl;
}

int main() {
    string* strArr = new string[6] {"aaa", "aa", "b", "h", "ab", "jj"};
    F<string> fstr;
    sort(strArr, strArr+5, fstr);
	print(strArr, strArr+5);

    int* arr = new int[8] {11, 0, -5, 4, 9, 1, 6, -8};
    sort(arr, arr+7, greater<int>());
	print(arr, arr+7);

    vector<double> vec = {0.1, 11.5, 6, -5.5, 9.9};
    sort(vec.begin(), vec.end(), F<double>());
	print(vec.begin(), vec.end()); //std::cout << std::flush;
}
