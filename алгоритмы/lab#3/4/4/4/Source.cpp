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
        cout << "Крыса, ";
        break;
    case 1:
        cout << "Корова, ";
        break;
    case 2:
        cout << "Тигр, ";
        break;
    case 3:
        cout << "Заяц, ";
        break;
    case 4:
        cout << "Дракон, ";
        break;
    case 5:
        cout << "Змея, ";
        break;
    case 6:
        cout << "Лошадь, ";
        break;
    case 7:
        cout << "Овца, ";
        break;
    case 8:
        cout << "Обезьяна, ";
        break;
    case 9:
        cout << "Петух, ";
        break;
    case 10:
        cout << "Собака, ";
        break;
    case 11:
        cout << "Свинья, ";
        break;
    }

    switch (color) {
    case 0:
    case 1:
        cout << "Зелёный";
        break;
    case 2:
    case 3:
        cout << "Красный";
        break;
    case 4:
    case 5:
        cout << "Жёлтый";
        break;
    case 6:
    case 7:
        cout << "Белый";
        break;
    case 8:
    case 9:
        cout << "Чёрный";
        break;
    }

    cout << endl;

    system("pause");
    return 0;
}