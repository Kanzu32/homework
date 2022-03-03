#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// 30. Напишите рекурсивную функцию root (а, b, e), которая методом деления отрезка пополам находит с точностью e корень уравнения f(x) = 0 на отрезке [а, b] (считать, что e > 0, а < b, f(a) - f(b) < 0 и f(x) – непрерывная и монотонная на отрезке [а, b] функция).
double root(double a, double b, double e);
double f(double x);

// 30. Используя рекурсивную функцию, для заданного числа n определить значение выражения
// ∑ ∏ f(x)
// i j
// где f(x) = x^(i+j) x – действительное число, i = 0,1,...n j = 1, 3,..., 2n−1.
double fMul(int i, int j, double x);
double fSum(int i, int j, double x);

int main() {
	int taskNumber;

	cin >> taskNumber;

	while (!cin.eof())
	{
		switch (taskNumber)
		{
		case 1:
			double a, b, e;
			cout << "a, b, e: ";
			cin >> a >> b >> e;
			cout << "result: " << root(a, b, e) << endl;
			cin >> taskNumber;
			break;

		case 2:
			int n, x, i, j;
			cout << "n, x: ";
			cin >> n >> x;
			i = n;
			j = n*2-1;
			cout << "result: " << fSum(i, j, x) << endl;
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
double root(double a, double b, double e) {
	double mid = (a+b)/2.0;
	double funcRes = f(mid);

	if ( (mid <= a+e && funcRes > e) || (mid >= b - e && funcRes < e) )
		return numeric_limits<double>::quiet_NaN();

	if (abs(funcRes) <= e) return mid;
	if (funcRes < -e) return root(mid, b, e);
	if (funcRes > e) return root(a, mid, e);

	return numeric_limits<double>::quiet_NaN();
}

double f(double x) {
	return x*2+2;
}

double fSum(int i, int j, double x) {
	if (i < 0) return 0;
	return fSum(i-1, j, x) + fMul(i, j, x);
}

double fMul (int i, int j, double x) {
	if (j < 1) return 1;
	return fMul(i, j-2, x) * pow(x, i+j);
}