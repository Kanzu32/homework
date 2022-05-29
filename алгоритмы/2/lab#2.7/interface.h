namespace interface {
	struct Array {
		int n;
		int m;
		int k;
		double *pointer;
		Array (int n1, int m1, int k1, double* arr) {
			n = n1;
			m = m1;
			k = k1;
			pointer = arr;
		}
	};

	void print(Array arr);
	void linearPrint(Array arr);

	Array createRandom(int n, int m, int k);
	Array create(int n, int m, int k, double val);

	Array copyArray(Array arr);

	Array cropArray(Array arr, int newN, int newM, int newK);

	int findElement(Array arr, bool mode);

	int findMatrix(Array arr, bool mode);

	void delMatrix(Array &arr, int n);
}