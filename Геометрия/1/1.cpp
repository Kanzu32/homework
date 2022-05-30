#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	double x;
	double y;
	double z;
};

struct Vector {
	double x;
	double y;
	double z;

	Vector(double a, double b, double c) {
		x = a;
		y = b;
		z = c;
	}

	Vector(Point a, Point b) {
		x = b.x-a.x;
		y = b.y-a.y;
		z = 0;
	}
};

int skewProduct(Vector v1, Vector v2) {
	return v1.x*v2.y - v2.x*v1.y;
}

// 1: кол-во левых и правых поворотов.
void taskOne();

// double leng(Point a, Point b) {
// 	return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
// };

// struct Triangle {
// 	Point a;
// 	Point b;
// 	Point c;
// };
// double perim(Triangle t) {
// 	return leng(t.a, t.b)+leng(t.b, t.c)+leng(t.a, t.c);
// }
// double area(Triangle t) {
// 	double p = perim(t)/2;
// 	return sqrt(p * (p - leng(t.a, t.b)) * (p - leng(t.a, t.c)) * (p - leng(t.b, t.c)));
// }
// double areaN(Point* p, int n) {
// 	Point fixed = p[0];
// 	double sum;
// 	for (int i = 2; i < n; i++) {
// 		sum += area(Triangle{fixed, p[i - 1], p[i]});
// 	}
// 	return sum;
// }

// Принадлежит ли точка к треугольнику
void taskTwo();

void taskThree();

int main()
{
	int taskNumber;
	cout << "task number: ";
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

void taskOne () {
	int n, leftCount = 0, rightCount = 0;
	double a, b;
	cout << "Number of points: ";
	cin >> n;
	Point *points = new Point[n];
	for (int i = 0; i < n; i++) {
		cout << "Point: ";
		cin >> a >> b;
		points[i] = Point{a, b, 0};
	}
	for (int i = 0; i < n; i++) {

		double product = skewProduct(Vector(points[i], points[(i+1) % n]), Vector(points[(i+1) % n], points[(i+2) % n]));
		if (product < 0)
			rightCount++;
		else if (product > 0)
			leftCount++;
	}

	cout << "Left turns: " << leftCount << '\n'
		 << "Right turns: " << rightCount << '\n';
}

void taskTwo() {
	Point *triangle = new Point[3];
	Point point;
	bool fl = true;
	double a, b;
	for (int i = 0; i < 3; i++) {
		cout << "Triangle point: ";
		cin >> a >> b;
		triangle[i] = Point{a, b, 0};
	}
	cout << "Point for check: ";
	cin >> a >> b;
	point = Point{a, b, 0};

	for (int i = 0; i < 3; i++) {
		double product1 = skewProduct(Vector(triangle[i], triangle[(i+1)%3]), Vector(triangle[i], point));
		double product2 = skewProduct(Vector(triangle[i], triangle[(i+1)%3]), Vector(triangle[i], triangle[(i+2)%3]));
		if (product1/abs(product1) != product2/abs(product2) && product1 != 0) {
			fl = false;
			break;
		}
	}

	if (fl)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

void taskThree() {
	
}