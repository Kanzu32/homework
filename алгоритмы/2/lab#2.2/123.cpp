#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(float *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void readArrayFromDataFile(float *&arr, int &n)
{
	ifstream file;
	file.open("C:\\Users\\Max\\Downloads\\myfile_1.data", ios::binary);
	float f;
	file.read(reinterpret_cast<char *>(&f), sizeof(float));
	n = (int)f;
	arr = new float[n];
	file.read(reinterpret_cast<char *>(arr), sizeof(float) * n);
	file.close();
}

int main()
{
	int n;
	float *arr;
	readArrayFromDataFile(arr, n);
	printArray(arr, n);
}



