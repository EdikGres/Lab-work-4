#include "pch.h"
#include "../Lab-work-4/Functions.h"


TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
using namespace func;

TEST(IsNumberFunc, numbersTest) {

	EXPECT_EQ(isNumber('4'), 1);

	EXPECT_EQ(isNumber('9'), 1);
	EXPECT_EQ(isNumber('1'), 1);
	EXPECT_EQ(isNumber('0'), 1);

	EXPECT_EQ(isNumber('d'), 0);


}

TEST(IsUniqueNum, FirstTest) {
	//если элемента нет в массиве - 1, иначе - 0
	int mass[] = {5, 24, 635, 1, 42, -13}; //first element - lenght
	int len = mass[0];

	int first = 24;
	int second = 444;
	int third = 1;
	
	int minus = -13;

	EXPECT_EQ(isUniqueNum(mass, len, first), 0);
	EXPECT_EQ(isUniqueNum(mass, len, second), 1);
	EXPECT_EQ(isUniqueNum(mass, len, third), 0);
	EXPECT_EQ(isUniqueNum(mass, len, 5), 1); // проверка на игнорирование первого символа
	EXPECT_EQ(isUniqueNum(mass, len, -13), 0); //проверка последнего символа
}
