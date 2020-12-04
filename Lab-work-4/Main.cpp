#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "MyLibForLab.h"

//const int MAX_MASS_SIZE = 256;
/*
	создать MAP для чисел в строке.
	ключ - само число. value - количество чисел
	(ключ уникален)

*/

using namespace mylab;
int main() {

	char* text;
	int text_len = 0;
	printf("Input text: ");
	text = get_string(&text_len);

	int numbers_len = 0;
	
	printf("All number from text:\n");
	
	int* numbers = getNumbers(text, &numbers_len);
	int i = 0;
	while (i < numbers_len)
	{
		printf("%d ", numbers[i]);
		i++;
	}

	int set_len = 0;
	int* set_numbers = uniqueNumbers(numbers, numbers_len, &set_len);

	printf("\nSET numbers:\n");
	i = 0;
	while (i < set_len)
	{
		printf("%d ", set_numbers[i]);
		i++;
	}
	free(text);
	free(numbers);
	free(set_numbers);
	return 0;
}





