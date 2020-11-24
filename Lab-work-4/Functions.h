#include <stdio.h>
#include <stdlib.h>

namespace func {

	int isNumber(char ch); //проверка на число
	int makeInteger(const char* c); //из строки извлечь первую цифру (альтернатива atoi)
	int isSign(char ch); // проверка является ли символ знаком + -
	int* getNumbers(char* str);// получить все цифры из строки
	int isUniqueNum(int* mass, int len, int num); //есть ли число в массиве - 1 если нет - 0
	int* uniqueNumbers(int* numbers, int len); //получить все уникальные цифры (SET) из массива с цифрами






}