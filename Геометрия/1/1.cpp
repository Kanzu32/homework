#include <iostream>
#include <cmath>
#include <stdexcept>

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

double leng(Point a, Point b) {
	return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
};

struct Triangle {
	Point a;
	Point b;
	Point c;
};
double perim(Triangle t) {
	return leng(t.a, t.b)+leng(t.b, t.c)+leng(t.a, t.c);
}
double area(Triangle t) {
	double p = perim(t)/2;
	return sqrt(p * (p - leng(t.a, t.b)) * (p - leng(t.a, t.c)) * (p - leng(t.b, t.c)));
}
double areaN(Point* p, int n) {
	Point fixed = p[0];
	double sum;
	for (int i = 2; i < n; i++) {
		sum += area(Triangle{fixed, p[i - 1], p[i]});
	}
	return sum;
}

// Принадлежит ли точка к треугольнику
void taskTwo();

void taskThree();

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
	double x1, y1, x2, y2, x1_, y1_, x2_, y2_;
	cout << "Enter coordinates: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x1_ >> y1_ >> x2_ >>y2_;
	Point p1{x1, y1};
	Point p2{x2, y2};
	Point p3{x1_,y1_};
	Point p4{x2_, y2_};
	if (skewProduct(Vector(p1, p3), Vector(p1, p2)) == 0 || skewProduct(Vector(p2, p3), Vector(p2, p1)) == 0 || skewProduct(Vector(p2, p4), Vector(p2, p1)) == 0 || skewProduct(Vector(p3, p1), Vector(p3, p4)) == 0 || skewProduct(Vector(p3, p2), Vector(p3, p4)) == 0 || skewProduct(Vector(p4, p1), Vector(p4, p3)) == 0 || skewProduct(Vector(p4, p2), Vector(p4, p3))==0){
		cout << "ti ne zaichik";

	}
	else if (skewProduct(Vector(p1, p3), Vector(p1, p2)) / abs(skewProduct(Vector(p1, p3), Vector(p1, p2))) != skewProduct(Vector(p1, p4), Vector(p1, p2)) / abs(skewProduct(Vector(p1, p4), Vector(p1, p2))) &&
				skewProduct(Vector(p2, p3), Vector(p2, p1)) / abs(skewProduct(Vector(p2, p3), Vector(p2, p1))) != skewProduct(Vector(p2, p4), Vector(p2, p1)) / abs(skewProduct(Vector(p2, p4), Vector(p2, p1))) && skewProduct(Vector(p3, p1), Vector(p3, p4)) / abs(skewProduct(Vector(p3, p1), Vector(p3, p4))) != skewProduct(Vector(p3, p2), Vector(p3, p4)) / abs(skewProduct(Vector(p3, p2), Vector(p3, p4))) && skewProduct(Vector(p4, p1), Vector(p4, p3)) / abs(skewProduct(Vector(p4, p1), Vector(p4, p3))) != skewProduct(Vector(p4, p2), Vector(p4, p3)) / abs(skewProduct(Vector(p4, p2), Vector(p4, p3))))
		{
			cout << "true";
		}
		else
		{
			cout << "false";
		}
}