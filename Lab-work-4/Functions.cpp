#include "Functions.h"

namespace func {

	int isNumber(char ch) {

		if (ch >= '0' && ch <= '9')
		{
			return 1;
		}
		return 0;


	}
    //�� ������ �������� ��� ������ �� ������ int
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
			������������ � ���� �������.
			��������� ������ � ������� � �������, ��������� �� �� �����. �������� �� �������: isNumber(), makeInteger() � isSign() � ������ ����������.
			���������� � ������� �������� ����� �������, � ��������� ��� �����.
			������ � ��� ����� �������� � ++i, ����� ������ ����� �� ������ � �����������, �.�. �����
			***������� ������ ��� ����, ����� �� ������� ������� ��� �-��� main() � �� ���� ��������� �� �������.***
	
	*/
    int* getNumbers(char* str) {

		char* temp = (char*)malloc(sizeof(char) * 100);
		int* mass = (int*)malloc(sizeof(int) * 256);

		int i = 0; // �������� ��� ��������� �������
		int j = 0; // �������� ��� ������� temp, ���������� ����� ��������� ����������� �����
		int m = 1; // �������� ��� ������� � �������, m = 1, �.�. � ������� �������� � ������� ������ �������.!!!!!!!!!!!
		int havenum = 0; // �������� ���� �� �����, ����� ������� isDigit �� ���������� ���� � ������ � �������.
		while (str[i] != 0)
		{
			char* temp = (char*)malloc(sizeof(char) * 100); //�������� ���������� ��������� ��� ���� � ������� char

			while (str[i] != 0 && (isNumber(str[i]) || (isSign(str[i]) && isNumber(str[i + 1]))))  /*
																								   ���������� ������ ������� � �����, ����� ���� ������ if'��. ���� ������, ��
																								   ������� �������� (str !=0 && (�����.�������) )   ���� ��������������� ���, ���� �����������.
																								   ���������� �������� ( isNumber || ( isSign && isNumber(i-1) ) ) ������ ����� ���, �������� �� ������ �����, ������ ����� ���
																								   �������� �� ���� +-, ��� ���� ��������, ��� ����� ����� ��� �����, � �� �����.
																								   */
			{
				havenum = 1; //���� �����!
				temp[j++] = str[i++]; //���������� ���������� ��������� �������
			}
			if (havenum == 1) //���� ������� �����, �������� ����� � ������ int
			{
				mass[m++] = makeInteger(temp); //��� ����� �� ���� atoi
			}
			havenum = 0; // �������� ������� �����

			j = 0; //�������� ������� ���������� ��������� � �������
			free(temp); // ���������� ������, ���������� ��� ���������� ���������

			i++;
		}
		mass[0] = m-1; //������� ������ �������

		return mass;

    }

	/*
		�������� ��� ������� isUnique() ++j, �� ������� ��� �������� �������������, �������� ���������� ����������� =)
		���������� false, ���� ������� ���� � �������. true, ���� ������.
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
		if (counter > 0) //������ > 0 ���������� ��� �-��� get_unique_letters(), ���� ����� ������ �������, �� ������� > 1 !!!!!!
		{
			return 0;
		}
		return 1;




	}
	/*
		�������� ��� ������� getNumbers() ++j, �� ������� ��� �������� �������������, �������� ���������� ����������� =)
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