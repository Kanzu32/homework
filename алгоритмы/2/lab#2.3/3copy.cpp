#include <stdio.h>
#include <string.h>

// 27. Написать функцию, выполняющую сортировку символов в заданной строке(по возрастанию или убыванию кодов ASCII).Функция должна иметь прототип: void strsort(char *str, bool f), где str – строка - источник, f – признак сортировки, например f = true – сортировка по возрастанию, f = false – сортировка по убыванию.

void strsort(char *str, bool f);

int main() {
	char str[100];
	int mode;
	scanf("%s", str);
	getchar();
	scanf("%i", &mode);

	strsort(str, mode);
	printf("%s", str);

}

void strsort(char *str, bool f) {
	int len = strlen(str);
	char temp;
	for (int x = 0; x < len; x++) {
		for (int i = 0; i < len-x-1; i++) {

			if (*(str+i) > *(str+i+1) && f) {
				temp = *(str+i);
				*(str+i) = *(str+i+1);
				*(str+i+1) = temp;
			}

			if (*(str+i) < *(str+i+1) && !f) {
				temp = *(str+i);
				*(str+i) = *(str+i+1);
				*(str+i+1) = temp;
			}
		}
	}
}