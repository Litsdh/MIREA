#include <stdio.h>
#include <stdlib.h>
#include "method.h"

int main(int argc, char* argv[])
{
	
	if((argc - 3) % 3 != 0)
	{
        	printf("Недостаточно количество аргументов или отсутствует значение ключа\n");
        	return 1;
	}
	
	// Создание динамического массива
	int *arr = (int *)malloc((argc-3)/3 * sizeof(int));	
	
	// Значение ключа
	long int key;
	
	// Переменная, которая записывает ошибки в значении ключа
	char *errkey;

	// Проверка на правильность флага, иначе программа возвращает 1
	if(argv[argc-2][0] == '-' && argv[argc-2][1] == 'k' && argv[argc-2][2] == '\0')
	{
		// Проверка на значение ключа, если ключ отсутствует, возвращает 1
    		if(*argv[argc-1] == '\0')
    		{
        		printf("Отсутствует значение ключа\n");
        		free(arr);
        		return 1;
    		}
   
		// Присвоение переменной key и errkey значение ключа и ошибок в нём соответственно,
		// при непустом переменной errkey программа возвращает 1
		key = strtol(argv[argc-1], &errkey, 10);
        	if(*errkey != '\0')
        	{
            		printf("Неправильное значение ключа: %s\n", argv[argc-1]);
            		free(arr);
			return 1;
        	}
    	
	}
	else
	{
    		printf("Неправильный флаг: %s\n", argv[argc-2]);
		free(arr);
		return 1;
	}	

	// Перебор пар из 3 символов
	for(int i = 2; i < argc - 2; i += 3)
	{	
		// Выход из цикла при 
		if(argv[i+1] == NULL)
		{
			break;
		}
		
		// Переменные err1 и err2, содержащие ошибки вводов операндов
		char *err1, *err2;
		
		// Значение левого (num1), правого (num2) операндов и их результата (res)
		long int num1 = strtol(argv[i-1], &err1, 10), num2 = strtol(argv[i+1], &err2, 10), res;
		
		// Если переменные err1 и err2 непустые, программа возвращает 1
		if(*err1 != '\0')
		{
			printf("Неправильный ввод операнда: %s\n", argv[i-1]);
			free(arr);
			exit(1);
		}
		else if(*err2 != '\0')
		{
			free(arr);
			printf("Неправильный ввод операнда: %s\n", argv[i+1]);
			exit(1);
		}	
		

		// Присвоение переменной res результат фунции arf, определенной в файле method.c
		res = arf(&num1, &num2, &argv[i][0], &arr);	

		// Добавление результата в массив
		arr[i/3] = res;
		
		// Вывод ответов
		printf("Ответ №%d: %d\n", i/3+1, arr[i/3]);	
	}
	

	// Вывод результирующей строки через функцию res_str, определённую в файле method.c
	res_str(&argc, &key, &arr);
		
	// Освобождение массива
	free(arr);
	
	return 0;
}
