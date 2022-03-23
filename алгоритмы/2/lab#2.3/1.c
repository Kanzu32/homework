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
	
	strcat(res, strrchr(str1, symbol));
	strncat(res, strchr(str2, symbol), n);
	printf("%s", res);
}