#ifndef INTERFACE_H
#define INTERFACE_H
#include "interface.h"
#endif

#include <iostream>
#include <iomanip>

using namespace interface;
namespace realisation {
	Array create(int n, int m, int k, double val) {
		double* arr = new double[n*m*k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int x = 0; x < k; x++) {
					*(arr + i*m*k + j*k + x) = val;
				}
			}
		}
		return Array(n, m, k, arr);
	}

	Array createRandom(int n, int m, int k) {
		double* arr = new double[n*m*k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int x = 0; x < k; x++) {
					*(arr + i*m*k + j*k + x) = (double)(std::rand() % 100);
				}
			}
		}
		return Array(n, m, k, arr);
	}

	Array copyArray(Array arr) {
		double *newArr = new double[arr.n * arr.m * arr.k];
		for (int i = 0; i < arr.n; i++) {
			for (int j = 0; j < arr.m; j++) {
				for (int x = 0; x < arr.k; x++) {
					*(arr.pointer + i*arr.m*arr.k + j*arr.k + x) = *(arr.pointer + i*arr.m*arr.k + j*arr.k + x);
				}
			}
		}
		return Array(arr.n, arr.m, arr.k, newArr);
	}

	void print(Array arr) {
		std::cout << "----START----\n";
		for (int x = 0; x < arr.n; x++) {
			std::cout << "Matrix [" << x+1 << "]\n";
			for (int i = 0; i < arr.m; i++) {
				for (int j = 0; j < arr.k; j++) {
					std::cout << std::setw(4) << std::setprecision(3) << *(arr.pointer + x*arr.m*arr.k + i*arr.k + j) << " ";
				}
				std::cout << "\n";
			}
			std::cout << "---------\n";
		}
		std::cout << "----END----\n";
	}

	void linearPrint(Array arr) {
		for (int i = 0; i < arr.k*arr.m*arr.n; i++) {
			std::cout << *(arr.pointer + i) << " ";
		}
	}

	Array cropArray(Array arr, int newN, int newM, int newK) {
		if (newN > arr.n || newM > arr.m || newK > arr.k) {
			std::cout << "error!";
			return create(newN, newM, newK, 0);
		}
		double *newArr = new double[newN * newM * newK];
		for (int i = 0; i < newN; i++) {
			for (int j = 0; j < newM; j++) {
				for (int x = 0; x < newK; x++) {
					*(newArr + i*newM*newK + j*newK + x) = *(arr.pointer + i*arr.m*arr.k  + j*arr.k + x);
				}
			}
		}
		return Array(newN, newM, newK, newArr);
	}

	int findElement(Array arr, bool mode) {
		int index = 0;
		if (mode) {
			double max = *(arr.pointer);
			for (int i = 0; i < arr.n*arr.m*arr.k; i++) {
				if (*(arr.pointer+i) > max) {
					max = *(arr.pointer + i);
					index = i;
				}
			}
		} else {
			double min = *(arr.pointer);
			for (int i = 0; i < arr.n*arr.m*arr.k; i++) {
				if (*(arr.pointer+i) < min) {
					min = *(arr.pointer + i);
					index = i;
				}
			}
		}
		return index;
	}

	int findMatrix(Array arr, bool mode) {
		int elIndex = realisation::findElement(arr, mode);
		return elIndex/(arr.m*arr.k);
	}

	void delMatrix(Array &arr, int index) {
		double* newArr = new double[(arr.n-1)*arr.m*arr.k];
		for (int x = 0; x < index; x++) {
			for (int i = 0; i < arr.m; i++) {
				for (int j = 0; j < arr.k; j++) {
					*(newArr + x*arr.m*arr.k + i*arr.k + j) = *(arr.pointer + x*arr.m*arr.k + i*arr.k + j);
				}
			}
		}

		for (int x = index+1; x < arr.n; x++) {
			for (int i = 0; i < arr.m; i++) {
				for (int j = 0; j < arr.k; j++) {
					*(newArr + (x-1)*arr.m*arr.k + i*arr.k + j) = *(arr.pointer + x*arr.m*arr.k + i*arr.k + j);
				}
			}
		}
		delete [] arr.pointer;
		arr.pointer = newArr;
		arr.n--;
		
	}
}