#include "method.h"
#include <stdio.h>

int arf(int *n1, int *n2, char *s, bool *p)
{
	// Разыменовываем указатели и присваиваем в переменные
	int num1 = *n1, num2 = *n2; char symb = *s;
	
	// Результат арифметического вычисления
	int arf;

	switch(symb)
	{
		case '+': arf = num1 + num2; break;
		case '-': arf = num1 - num2; break;
		case '*': arf = num1 * num2; break;
		case '%': if(num2 != 0)
			  {
				  arf = num1 % num2; break;
			  }
			  else
			  {
				  printf("Деление на 0\n"); *p = false; break;
			  }
		default: printf("Некорректный оператор: %c\n", symb); *p = false; break;
	}
	return arf;
}


int res_str(int *argc, int *key, int **arr)
{
	printf("Результирующая строка: ");
	for(int i = 0; i < (*argc-3)/3; i++)
	{
		printf("%c", (*arr)[i] - *key);
	}
	printf("\n");
	return 0;
}

