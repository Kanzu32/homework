#include <stdio.h>
#include <string.h>

// 27. Дан текст, слова в котором разделены одинарным символом пробела (в тексте могут встречаться запятые), и какая-то буква. Вывести все слова текста, у которых последняя буква не совпадает с заданной.

int main() {
	char str[1000];
	char c;
	fgets(str, 100, stdin);
	scanf("%c", &c);
	fflush(stdin);

	char *cptr = strtok(str, " ,");
	
	while (cptr != NULL) {
		if (cptr[strlen(cptr)-1] != c) {
			printf("%s\n", cptr);
		}
		cptr = strtok(NULL, " ,");
	}
	

}