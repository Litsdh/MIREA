#include "method.h"
#include <stdio.h>
#include <stdlib.h>

// Функция вычисления арифметического выражения
int arf(long int *n1, long int *n2, char *s, int **arr)
{
	// Разыменовываем указатели и присваиваем в переменные
	long int num1 = *n1, num2 = *n2; char symb = *s;	
	// Результат арифметического вычисления
	long int arf;

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
				  printf("Деление на 0\n"); free(*arr); exit(1);
			  }
		default: printf("Некорректный оператор: %c\n", symb); free(*arr); exit(1);
	}
	return arf;
}



// Функция вычисления результирующей строки
int res_str(int *argc, long int *key, int **arr)
{
	printf("Результирующая строка: ");
	for(int i = 0; i < (*argc-3)/3; i++)
	{
		printf("%c", (*arr)[i] - *key);
	}
	printf("\n");
	return 0;
}

