#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
//#include <iomanip>
//#include <algorithm>
using namespace std;


// #1
// Дан массив действительных чисел размера n.Выполнить сортировку элементов массива,
// расположенных между его максимальным по модулю и минимальным помодулю элементами,
// по убыванию, составив функцию, результатом которой является отсортированный массив.
// В качестве аргументов функции использовать параметры сортировки, указатель на массив и его размер.
void taskOne();
void findMinMax(double* arr, int n, int& maxIndex, int& minIndex);
void sort(double*& arr, int maxIndex, int minIndex);

// #2
// Дана матрица A действительных чисел размера n×m.Составив функцию, для поиска максимального элемента в указанной строке двумерного массива, сдвинуть в матрице A все строки циклически вправо на количество элементов равное максимальному элементу в этой строке.
void taskTwo();
double findMaxInRow(double **arr, int row, int m);
int countElementsInRow(double **arr, int row, int m, double value);
void shiftMatrix(double **arr, int n, int m);

// #3
// Описать функцию LinearSystemSolve(A1, B1, C1, A2, B2, C2, X, Y), решающую систему из двух линейных уравнений : A1 · X + B1 · Y = C1, A2 · X + B2 · Y = C2 и возвращающую результат через ссылки X и Y(A1, B1, C1, A2, B2, C2, X, Y – вещественные).Функция должна возвращать целое значение: 1, если существует ровно одно решение, 0, если система не имеет решений, и -1, если система имеет бесконечно много решений.С помощью этой функции найти решение двух систем линейных уравнений с двумя неизвестными, заданных двумя наборами из шести чисел : (A1, B1, C1, A2, B2, C2)и(A2, B2, C2, A3, B3, C3).Вывести на экран значения корней или сообщения: «решений нет» или «решений бесконечно много».
void taskThree();
int LinearSystemSolve(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y);
void solve(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y);

int main() {
	int taskNumber;
	srand(time(NULL));

	cin >> taskNumber;
	
	while (!cin.eof()) {
		switch (taskNumber) {
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

void taskOne() {
	int n, maxIndex, minIndex;
	cout << "input count of numbers: ";
	cin >> n;
	double *arr = new double[n];
	for (int i = 0; i < n; i++) {
		arr[i] = ( (rand() % 10000) / 100.0) - 50;
		cout << arr[i] << " ";
	}

	findMinMax(arr, n, maxIndex, minIndex);
	cout << "\nMin index: " << minIndex << " max index: " << maxIndex << "\n";
	sort(arr, maxIndex, minIndex);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void findMinMax(double *arr, int n, int &maxIndex, int &minIndex) {
	double maxValue = arr[0], minValue = arr[0];
	for (int i = 0; i < n; i++) {
		if (abs(maxValue) < abs(arr[i])) {
			maxValue = arr[i];
			maxIndex = i;
		}

		if (abs(minValue) > abs(arr[i])) {
			minValue = arr[i];
			minIndex = i;
		}
	}
}

void sort(double*& arr, int maxIndex, int minIndex) {
	int start, end;

	if (minIndex > maxIndex) {
		start = maxIndex+1;
		end = minIndex-1;
	} else {
		start = minIndex+1;
		end = maxIndex-1;
	}

	for (int x = start; x < end; x++) {
		for (int i = start+1; i <= end; i++) {
			if (abs(arr[i-1]) > abs(arr[i])) swap(arr[i-1], arr[i]);
		}
	}
}

void taskTwo() {
	int n = 3, m = 3;
	cout << "size of matrix: ";
	cin >> n >> m;
	
	double** arr = new double*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[m];
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	shiftMatrix(arr, n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void shiftMatrix(double **arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		double max = findMaxInRow(arr, i, m);
		int shift = countElementsInRow(arr, i, m, max);

		double* temp = new double[shift];
		for (int x = 0; x < shift; x++) {
			temp[x] = arr[i][m - x-1];
		}

		for (int j = m - 1; j >= 0; j--) {
			if (j < shift) {
				arr[i][j] = temp[j];
			} else {
				arr[i][j] = arr[i][j - shift];
			}
		}
	}
}

double findMaxInRow(double** arr, int row, int m) {
	double max = arr[row][0];
	for (int i = 1; i < m; i++) {
		if (max < arr[row][i]) {
			max = arr[row][i];
		}
	}
	return max;
}

int countElementsInRow(double** arr, int row, int m, double value) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		if (arr[row][i] == value) {
			count++;
		}
	}
	return count;
}

void taskThree() {
	double a1, b1, c1, a2, b2, c2, x, y;
	//cout << "a1, b1, c1, a2, b2, c2: ";
	//cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	solve(0, 0, 0, 0, 0, 0, x, y);
	solve(2, 5, 31, 1, 1, 8, x, y);
	solve(3, 10, 4, 6, 20, 8, x, y);
	solve(3, 10, 4, 6, 20, 13, x, y);
	
}

int LinearSystemSolve(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y) {

	if ((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0)) {
		return 0;
	}

	if ((a1 == 0 && b1 == 0 && c1 == 0) || (a2 == 0 && b2 == 0 && c2 == 0)) {
		return -1;
	}

	if (a1 / b1 == a2 / b2) {
		if (c1/b1 == c2/b2) {
			return -1;
		} else {
			return 0;
		}
	}
	

	if (a1 == 0) {
		y = c1/b1;
		x = (c2-b2*y)/a2;
	} else if (b1 == 0) {
		x = c1/a1;
		y = (c2-a2*x)/b2;
	} else if (a2 == 0) {
		y = c2 / b2;
		x = (c1 - b1 * y) / a1;
	} else if (b2 == 0) {
		x = c2 / a2;
		y = (c1 - a1 * x) / b1;
	} else {
		y = (c2 - (a2 * c1 / a1)) / (b2 - (a2 * b1 / a1));
		x = (c1 - b1 * y) / a1;
	}
	
	return 1;
}

void solve(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y) {
	int res = LinearSystemSolve(a1, b1, c1, a2, b2, c2, x, y);
	if (res == -1) {
		cout << "infinitely many solutions\n";
	} else if (res == 0) {
		cout << "no solutions\n";
	} else {
		cout << x << " " << y << '\n';
	}
}