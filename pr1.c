#include <stdio.h>
#include <stdlib.h>
#include "method.h"

int main(int argc, char* argv[])
{
	// Проверка на обнаружение ошибки в флаге и ключе
	bool provkey = true;

	// При отсутствие или недостаточном кол-ве аргументов присваивает переменной prov значение false
	if((argc - 3) % 3 != 0)
	{
        	printf("Недостаточно количество аргументов или отсутствует значение ключа\n");
        	provkey = false;
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
	
	
		// Проверка на значение ключа, если ключ отсутствует, prov принимает значение false
    		if(*argv[argc-1] == '\0')
    		{
        		printf("Отсутствует значение ключа\n");
        		provkey = false;
    		}
   
		// Присвоение переменной key и errkey значение ключа и ошибок в нём соответственно,
		// при непустом переменной errkey переменная prov = false
		key = strtol(argv[argc-1], &errkey, 10);

        	if(*errkey != '\0')
        	{
            		printf("Неправильное значение ключа: %s\n", argv[argc-1]);
			provkey = false;
        	}
    	
	}
	else
	{
    		printf("Неправильный флаг: %s\n", argv[argc-2]);
		provkey = false;
		key = strtol(argv[argc-1], &errkey, 10);
		if(*errkey != '\0')
		{
			printf("Неправильное значение ключа: %s\n", argv[argc-1]);
		}
	}	

	// Проверка на ошибки в операнде и/или в операторе
	bool prov_arf;

	// Перебор пар из 3 символов
	for(int i = 2; i < argc - 2; i += 3)
	{	
		
		// Выход из цикла при достижении конца массива
		if(argv[i+1] == NULL)
		{
			break;
		}
		
		// Переменные err1 и err2, содержащие ошибки вводов операндов
		char *err1, *err2;

		prov_arf = true;

		// Значение левого (num1), правого (num2) операндов и их результата (res)
		long int num1 = strtol(argv[i-1], &err1, 10), num2 = strtol(argv[i+1], &err2, 10), res;

		// Если переменные err1 и err2 непустые, prov принимает значение false
		if(*err1 != '\0')
		{
			printf("Неправильный ввод операнда: %s\n", argv[i-1]);
			prov_arf = false;
		}
		else if(*err2 != '\0')
		{
			printf("Неправильный ввод операнда: %s\n", argv[i+1]);
			prov_arf = false;
		}	

		// Присвоение переменной res результат фунции arf, определенной в файле method.c
		res = arf(&num1, &num2, &argv[i][0], &arr, &prov_arf);	

		// Добавление результата в массив
		arr[i/3] = res;	
	}
	
	// Программа возвращает 1 и освобождает динамический массив, если обнаружены ошибки
	if(!provkey || !prov_arf)
	{
		free(arr);
		return 1;
	}

	// Вывод ответов
	for(int i; i < (argc-3)/3; i++)
	{
		printf("Ответ №%d: %d\n", i, arr[i]);
	}

	// Вывод результирующей строки через функцию res_str, определённую в файле method.c
	res_str(&argc, &key, &arr);
		
	// Освобождение массива
	free(arr);
	
	return 0;
}
