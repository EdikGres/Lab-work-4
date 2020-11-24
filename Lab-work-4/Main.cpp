
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

const int MAX_MASS_SIZE = 256;
using namespace func;
int main() {

	char* str = (char*)malloc(sizeof(char) * MAX_MASS_SIZE);
	printf("input text:");
	fgets(str, MAX_MASS_SIZE, stdin);

	int* nums = getNumbers(str);
	
	printf("\nAll numbers from text: \n");
	int i = 0;
	while (i < nums[0])
	{
		printf("%d ", nums[++i]);

	}
	
	printf("\nUnique numbers (SET): \n");

	int* unique = uniqueNumbers(nums, nums[0]);
	i = 0;
	while (i < unique[0])
	{
		printf("%d ", unique[++i]);
	}
	



	return 0;
}




