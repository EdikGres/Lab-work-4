#include <stdio.h>
#include <stdlib.h>

namespace func {

	int isNumber(char ch); //�������� �� �����
	int makeInteger(const char* c); //�� ������ ������� ������ ����� (������������ atoi)
	int isSign(char ch); // �������� �������� �� ������ ������ + -
	int* getNumbers(char* str);// �������� ��� ����� �� ������
	int isUniqueNum(int* mass, int len, int num); //���� �� ����� � ������� - 1 ���� ��� - 0
	int* uniqueNumbers(int* numbers, int len); //�������� ��� ���������� ����� (SET) �� ������� � �������






}