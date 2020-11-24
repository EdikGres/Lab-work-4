#include "Functions.h"

namespace func {

	int isNumber(char ch) {

		if (ch >= '0' && ch <= '9')
		{
			return 1;
		}
		return 0;


	}
    //не сделал отбойник для выхода за размер int
    int makeInteger(const char* c) {
        int value = 0;
        int sign = 1;
        if (*c == '+' || *c == '-') {
            if (*c == '-') sign = -1;
            c++;
        }
        while (isNumber(*c)) {
            value *= 10;
            value += (int)(*c - '0');
            c++;
        }
        return value * sign;
    }
    int isSign(char ch) {
        if (ch == '+' || ch == '-') {
            return 1;
        }
        return 0;

    }
	/*
			Документация к моей функции.
			Принимает строку с текстом и цифрами, извлекает из неё цифры. Зависима от функций: isNumber(), makeInteger() и isSign() в данной библиотеке.
			Возвращает в нулевом элементе длину массива, в остальных все числа.
			Работу с ним нужно начинать с ++i, чтобы первое число не попало в отображение, т.к. длина
			***Сделано сугубо для того, чтобы не портить внешний вид ф-ции main() и всё было аккуратно по фунциям.***
	
	*/
    int* getNumbers(char* str) {

		char* temp = (char*)malloc(sizeof(char) * 100);
		int* mass = (int*)malloc(sizeof(int) * 256);

		int i = 0; // итерация для основного массива
		int j = 0; // итерация для массива temp, обнуляется после окончания внутреннего цикла
		int m = 1; // итерация для массива с цифрами, m = 1, т.к. в нулевом элементе я передам длинну массива.!!!!!!!!!!!
		int havenum = 0; // проверка есть ли цифры, чтобы функция isDigit не возвращала нули в массив с цифрами.
		while (str[i] != 0)
		{
			char* temp = (char*)malloc(sizeof(char) * 100); //создание временного хранилища для цифр в формате char

			while (str[i] != 0 && (isNumber(str[i]) || (isSign(str[i]) && isNumber(str[i + 1]))))  /*
																								   Специально сделал условие в цикле, чтобы было меньше if'ов. Если кратко, то
																								   Внешняя проверка (str !=0 && (внутр.условие) )   Если удовлетворяются оба, цикл выполняется.
																								   Внутренняя проверка ( isNumber || ( isSign && isNumber(i-1) ) ) Первая часть или, проверка на просто число, вторая часть или
																								   проверка на знак +-, при этом проверка, что после знака идёт число, а не буква.
																								   */
			{
				havenum = 1; //есть цифры!
				temp[j++] = str[i++]; //заполнение временного хранилища цифрами
			}
			if (havenum == 1) //если имеются цифры, вставить число в массив int
			{
				mass[m++] = makeInteger(temp); //мой метод по типу atoi
			}
			havenum = 0; // обнулить наличие чисел

			j = 0; //обнулить счётчик временного хранилища с цифрами
			free(temp); // освободить память, выделенную для временного хранилища

			i++;
		}
		mass[0] = m-1; //вернуть размер массива

		return mass;

    }

	/*
		Подогнан под функцию isUnique() ++j, не годится для обычного использования, считайте внутренней реализацией =)
		возвращает false, если элемент есть в массиве. true, если чистый.
	*/
	int isUniqueNum(int* mass, int len, int num) {
		int i = 1;
		int counter = 0;
		while (i < len+1)
		{
			if (num == mass[i])
			{
				counter++;
			}
			i++;
		}
		if (counter > 0) //сделал > 0 специально для ф-ции get_unique_letters(), если нужна просто функция, то сделать > 1 !!!!!!
		{
			return 0;
		}
		return 1;




	}
	/*
		Подогнан под функцию getNumbers() ++j, не годится для обычного использования, считайте внутренней реализацией =)
	*/
	int* uniqueNumbers(int* numbers, int len) {
		int* temp = (int*)malloc(sizeof(int) * 256);
		int i = 0;
		int j = 1;
		
		temp[j++] = numbers[++i];

		while (i < len+1)
		{
			if (isUniqueNum(temp, len, numbers[i]))
			{
				temp[j++] = numbers[i];
			}
			i++;
		}
		temp[0] = j-1;

		return temp;

	}



}