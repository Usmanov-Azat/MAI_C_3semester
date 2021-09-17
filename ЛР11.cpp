
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h> 
#include<stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include<locale.h>
//Возвращаем "правду",если это ограничитель 
bool isDelimiter(char ch);//Проверка на разделители
bool isOperator(char ch);//Проверка на операторы
bool validIdentifier(char* str);//Проверка на идентификаторы
bool isKeyword(char* str);//Проверка на ключевые слова
bool isInteger(char* str);//Проверка на цифры
char* subString(char* str, int left, int right);
int main()
{

	//открытие текстового файла и проверка на его существование



	char* locale = setlocale(LC_ALL, "RUSSIAN");

	char str[256];//массив данных
	int len = 0;//длина текста файла
	int id = 0;//кол-во идентификаторов
	int count = 0;//проверка на пустоту
	int left = 0, right = 0;//индексы слов

	FILE* fp;
	//открытие текстового файла и проверка на его существование
	if ((fp = fopen("test.txt", "r")) == NULL) {

		printf("Невозможно открыть файл.\n");

		exit(1);

	}



	//чтение файла 
	while (fgets(str, 256, fp) != NULL) {

		count++;

		len = strlen(str);

	}
	if (count == 0)

	{

		printf("Файл пуст");

		exit(2);

	}

	printf("Идентификаторы:\n");
	while (right <= len && left <= right) {
		if (isDelimiter(str[right]) == false)
			right++;

		if (isDelimiter(str[right]) == true && left == right) {
			if (isOperator(str[right]) == true) {}
			right++;
			left = right;
		}
		else if (isDelimiter(str[right]) == true && left != right
			|| (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);

			if (isKeyword(subStr) == true) {}

			else if (isInteger(subStr) == true) {}

			else if (validIdentifier(subStr) == true
				&& isDelimiter(str[right - 1]) == false) {

				printf("'%s'\n ", subStr);
				id++;
			}

			else if (validIdentifier(subStr) == false
				&& isDelimiter(str[right - 1]) == false) {
			}

			left = right;
		}
	}

	printf("Количество идентификаторов равно: ");
	printf("%d", id);
	printf("\n");
	system("pause");
	return (0);
}
//Возвращате "правду" если это разделитель
bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return (false);
}

// Возвращаем "правду" если это оператор
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=')
		return (true);
	return (false);
}

// Возвращаем "правду" если это идентификатор
bool validIdentifier(char* str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isDelimiter(str[0]) == true)
		return (false);
	return (true);
}

// Возвращаем "правду",если это ключевые слова
bool isKeyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||
		!strcmp(str, "continue") || !strcmp(str, "int")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "return") || !strcmp(str, "char")
		|| !strcmp(str, "case") || !strcmp(str, "char")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "typedef")
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
		|| !strcmp(str, "void") || !strcmp(str, "static")
		|| !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}

// Возвращаем "правду", если это цифра 
bool isInteger(char* str)
{
	int i, len = strlen(str);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}



// Создаем массив для нашего идентификатора. 
char* subString(char* str, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(
		sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}