#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	int tokenStart = 0;
	int tokenEnd = 0;
	int len = 0;
	string left, right;
	bool fl;

	while (tokenEnd != str.length()) {
		tokenEnd = str.find(' ', tokenEnd);
		fl = true;
		len = tokenEnd - tokenStart;
		left = str.substr(tokenStart, len / 2);
		right = str.substr(tokenEnd - len / 2);

		if (tokenEnd == -1)
			tokenEnd = str.length()-1;
		
		for (int i = 0; i < len/2; i++) {
			if (left.at(i) != right.at(len/2-i-1)) {
				fl = false;
				break;
			}
		}
		if (fl) cout << str.substr(tokenStart, len) << " ";
		tokenEnd++;
		tokenStart = tokenEnd;
	}
}