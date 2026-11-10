#include <stdio.h>
#include <stdlib.h>
#include "method.h"

int main(int argc, char* argv[])
{
	
	// Создание динамического массива
	int *arr = (int *)malloc((argc-3)/3 * sizeof(int));	
	
	// Значение ключа
	int key;
	
	// Проверка на правильность оператора	
	bool op = true; 
	
	// Перебор пар из 3 символов
	for(int i = 2; i < argc; i += 3)
	{	
			
		if(argv[i+1] == NULL)
		{
			break;
		}
		// Значение левого (num1), правого (num2) операндов и их результата (res)
		int num1 = atoi(argv[i-1]), num2 = atoi(argv[i+1]), res;
		
		// Присвоение переменной res результат фунции arf, определенной в файле method.h
		res = arf(&num1, &num2, &argv[i][0], &op);
		
		// Выход из цикла, если оператор неккоректный
		if(!op)
		{
			break;
		}

		// Добавление результата в массив
		arr[i/3] = res;

		// Вывод ответов
		printf("Ответ №%d: %d\n", i/3+1, arr[i/3]);	
	}
	
	// Завершение программы при некорректном операторе
	if(!op)
	{
		return 1;
	}
	
	
	// Проверка корректного флага и ключа, и присвоение переменной key значение ключа
	if (argv[argc-2][0] == '-' && argv[argc-2][1] == 'k' && argv[argc-2][2] =='\0')
	{
		key = atoi(argv[argc-1]);
	}
	else
	{
		printf("Неправильный флаг: %s\n", argv[argc-2]);
		return 1;
	}

	// Вывод результирующей строки через функцию res_str, определённую в файле method.c
	res_str(&argc, &key, &arr);
		
	// Освобождение массива
	free(arr);
	
	return 0;
}
