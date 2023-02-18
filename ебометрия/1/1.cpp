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

double skewProduct(Vector v1, Vector v2) {
	return v1.x*v2.y - v2.x*v1.y;
}

double skalarProduct(Vector v1, Vector v2) {
	return v1.x*v2.x + v1.y*v2.y;
}

double distance(Point a, Point b) {
	return sqrt(pow(b.x - a.x, 2)+pow(b.y - a.y, 2));
}

double perpendicularDistance(Point a, Point b, Point c) {
	double A = c.y - b.y;
	double B = b.x - c.x;
	double C = c.x*b.y-b.x*c.y;

	return abs(A*a.x+B*a.y+C)/sqrt(A*A + B*B);
}

// 1: кол-во левых и правых поворотов.
void taskOne();

// Принадлежит ли точка к треугольнику
void taskTwo();

// Пересечение отрезков
void taskThree();

// Пересечение окружности и отрезка
void taskFour();

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
			cout << "task number: ";
			cin >> taskNumber;
			break;

		case 2:
			taskTwo();
			cout << "task number: ";
			cin >> taskNumber;
			break;

		case 3:
			taskThree();
			cout << "task number: ";
			cin >> taskNumber;
			break;
		case 4:
			taskFour();
			cout << "task number: ";
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
	double x1, y1, x2, y2, x1_, y1_, x2_, y2_, A1, B1, C1, A2, B2, C2, yP, xP;
	cout << "Enter coordinates: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x1_ >> y1_ >> x2_ >>y2_;

	A1 = y2-y1;
	B1 = x1-x2;
	C1 = x2*y1-x1*y2;

	A2 = y2_-y1_;
	B2 = x1_-x2_;
	C2 = x2_*y1_ - x1_*y2_;

	if (A1 == A2 && B1 == B2 && C1 == C2) {
		if ((max(x1, x2) >= min(x1_, x2_))) {
			cout << "true\n";
		} else {
			cout << "false\n";
		}
	} else if (A1*B2-A2*B1 == 0) {
		cout << "false\n";
	} else {
		yP = (A2*C1-A1*C2)/(A1*B2-A2*B1);
		xP = (B1*C2-B2*C1)/(A1*B2-A2*B1);

		cout << "Point projections "<< xP << " " << yP << "\n";

		if (((x1 <= xP && x2 >= xP) || (x1 >= xP && x2 <= xP)) &&
			((y1 <= yP && y2 >= yP) || (y1 >= yP && y2 <= yP))) {
				cout << "true\n";
			}
		else {
			cout << "false\n";
		}
	}
}

void taskFour() {
	double x0, y0, r, x1, y1, x2, y2, l;
	cout << "Enter x0, y0, r, x1, y1, x2, y2: ";
	cin >> x0 >> y0 >> r >> x1 >> y1 >> x2 >> y2;

	Point p0 = Point{x0, y0};
	Point p1 = Point{x1, y1};
	Point p2 = Point{x2, y2};

	if (skalarProduct(Vector(p1, p0), Vector(p1, p2)) < 0 || skalarProduct(Vector(p2, p0), Vector(p2, p1)) < 0) {
		l = min(distance(p0, p1), distance(p0, p2));
	}
	else {
		l = perpendicularDistance(p0, p1, p2);
	}
	cout << l << "\n";
	if (l < r) {
		cout << "true, 2 points\n";
	} else if (l == r) {
		cout << "true, 1 point\n";
	} else {
		cout << "false\n";
	}
}