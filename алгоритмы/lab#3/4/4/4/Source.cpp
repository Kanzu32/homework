#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, animal, color;
    cin >> n;
    animal = (n - 1984) % 12;
    color = (n - 1984) % 10;

    switch (animal) {
    case 0:
        cout << "�����, ";
        break;
    case 1:
        cout << "������, ";
        break;
    case 2:
        cout << "����, ";
        break;
    case 3:
        cout << "����, ";
        break;
    case 4:
        cout << "������, ";
        break;
    case 5:
        cout << "����, ";
        break;
    case 6:
        cout << "������, ";
        break;
    case 7:
        cout << "����, ";
        break;
    case 8:
        cout << "��������, ";
        break;
    case 9:
        cout << "�����, ";
        break;
    case 10:
        cout << "������, ";
        break;
    case 11:
        cout << "������, ";
        break;
    }

    switch (color) {
    case 0:
    case 1:
        cout << "������";
        break;
    case 2:
    case 3:
        cout << "�������";
        break;
    case 4:
    case 5:
        cout << "Ƹ����";
        break;
    case 6:
    case 7:
        cout << "�����";
        break;
    case 8:
    case 9:
        cout << "׸����";
        break;
    }

    cout << endl;

    system("pause");
    return 0;
}