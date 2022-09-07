#ifndef INTERFACE_H
#define INTERFACE_H
#include "interface.h"
#endif

#ifndef REALISATION_H
#define REALISATION_H
#include "realisation.h"
#endif

using namespace std;

int main() {
	// 32 вар. Удалить из массива матрицу, содержащую максимальное значение исходного массива;
	std::cout << "### TASK 1 ###\n";
	Array arr = realisation::createRandom(4, 2, 3);
	realisation::print(arr);
	realisation::delMatrix(arr, realisation::findMatrix(arr, 1));
	realisation::print(arr);

	// получить трехмерный подмассив исходного массива, находящийся между одним из углов исходного и вершиной, в которой содержится минимальное значение исходного массива.
	std::cout << "### TASK 2 ###\n";
	arr = realisation::createRandom(3, 3, 3);
	int minIndex = realisation::findElement(arr, 1);
	realisation::print(arr);
	cout << "Coordinates: " << minIndex/(arr.k*arr.m) << " " << (minIndex%(arr.k*arr.m))/arr.m << " " <<  minIndex%(arr.k*arr.m)%arr.m << "\n";
	Array arr1 = realisation::cropArray(arr, minIndex/(arr.k*arr.m)+1, (minIndex%(arr.k*arr.m))/arr.m+1, minIndex%(arr.k*arr.m)%arr.m+1);
	realisation::print(arr1);
}
