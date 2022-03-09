#include <stdio.h>
#include <string.h>

// 27. Даны две строки str1 и str2, символ symbol и целое n. Составить и вывести на экран новую строку, состоящую из частей: 1) все символы строки str1, начиная с последнего символа, совпадающего с symbol, заканчивая концом строки str1, 2) n первых символов строки str2,  начиная с первого символа, совпадающего с symbol.

int main() {
	char str1[100];
	char str2[100];
	char symbol;
	char res[200] = "";
	int iRes = 0;
	int n;
	
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);
	getchar();
	scanf("%c", &symbol);
	getchar();
	scanf("%i", &n);
	fflush(stdin);

	int startIndex1 = strrchr(str1, symbol) - str1;
	for (int i = startIndex1; i < strlen(str1); i++) {
		*(res + iRes) = *(str1 + i);
		iRes++;
	}

	int startIndex2 = strchr(str2, symbol) - str2;
	for (int i = startIndex2; i < startIndex2+n; i++) {
		*(res + iRes) = *(str2 + i);
		iRes++;
	}
	*(res + iRes) = '\n';
	printf("%s", res);

}