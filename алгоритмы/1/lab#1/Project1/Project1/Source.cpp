#include <iostream>

using namespace std;

int main()
{
	short T1;
	cin >> T1;

	double T2;
	T2 = T1;

	unsigned char T3;
	T3 = static_cast <unsigned char> (T1);

	int T4;
	T4 = (int) T1;

	cout << "T1 value: " << T1 << ", size: " << sizeof(T1) << " byte\n";
	cout << "T2 value: " << T2 << ", safety: safe" << ", size: " << sizeof(T2) << " byte\n";
	cout << "T3 value: " << T3 << ", safety: unsafe" << ", size: " << sizeof(T3) << " byte\n";
	cout << "T4 value: " << T4 << ", safety: safe"  << ", size: " << sizeof(T4) << " byte\n";

	system("pause");
	return 0;

}