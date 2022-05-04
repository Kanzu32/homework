#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

// 29. Описать тип Point - с полями вещественного типа x и y (координаты точки на плоскости) - и функцию leng(a, b) вещественного типа, находящую длину отрезка AB на плоскости по координатам его концов(a и b - параметры типа Point).Описать тип Triangle - с полями a, b, c типа Point(вершины треугольника) - и функцию perim(t) вещественного типа, находящую периметр треугольника t(t - параметр типа Triangle). Описать функцию area(t) вещественного типа, находящую площадь треугольника t (t - параметр типа Triangle) по формуле Герона.Описать функцию areaN(p, n) вещественного типа, находящую площадь выпуклого n - угольника, вершины которого(в порядке их обхода) передаются в массиве p размера n(> 2) с элементами типа Point.С помощью этой функции найти площади трех многоугольников, если дано число их сторон и координаты их вершин.
void taskOne();
struct Point {
	double x;
	double y;
};
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

// 29. Известны данные о росте 15 - ти юношей класса, упорядоченные по убыванию. Нет ни одной пары учеников, имеющих одинаковый рост. В начале учебного года в класс поступил новый ученик (известно, что его рост не совпадает с ростом ни одного из учеников класса, превышает рост самого низкого ученика и меньше роста самого высокого).  Получить новый список фамилий учеников (с учетом фамилии "новенького"), в котором фамилии расположены в порядке убывания роста.
void taskTwo();
struct Human {
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
	} else {
		sort(person.begin(), person.end(), decrease);
	}
}

//29. Создайте перечисляемый тип, описывающий производителей ноутбуков.
void taskThree();
enum Notebook{lenovo, acer, dell, msi, asus};

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
	int n;
	double a, b;
	cout << "Number: ";
	cin >> n;
	Point *arr = new Point[n];
	for (int i = 0; i < n; i++) {
		cout << "Point: ";
		cin >> a >> b;
		arr[i] = Point{a, b};
	}
	cout << areaN(arr, n) << '\n';
	
}

void taskTwo() {
	vector <Human> arr({Human{"b", 75}, Human{"a", 80}, Human{"d", 81}, Human{"c", 85}});
	string name;
	double height;
	bool mode;
	printStructArray(arr);
}

void printStructArray(vector<Human> arr) {
	for (Human i : arr) {
		cout << i.name << " " << i.height << "\n";
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

void taskThree() {
	Notebook n;
	int num;
	cout << "Number: ";
	cin >> num;
	n = (Notebook)num;
	setlocale(LC_ALL, "Rus");
	switch (n) {
	case lenovo: case asus:
		wprintf(L"Хороший выбор!");
		break;
	case dell: case acer:
		wprintf(L"Нормально.");
		break;
	case msi:
		wprintf(L"Осторожней с ним, а то развалится!");
		break;
	default:
		wprintf(L"С алиэкспресса брал?");
		break;
	}
}