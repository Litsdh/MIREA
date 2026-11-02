#include <stdio.h>
#include <stdlib.h>


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
			
		// Поиск результата по оператору, если оператор некорректный, то переменная op приравнивается false
		switch(argv[i][0])
		{
		case '+': res = num1 + num2; break;
                case '-': res = num1 - num2; break;
                case '*': res = num1 * num2; break;
                case '%': res = num1 % num2; break;
		default:  printf("Некорректный оператор: %c\n", argv[i][0]); op = false; break;
		}
			
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


	// Вычисление результирующей строки
	printf("Результирующая строка: ");
	for(int i = 0; i < (argc-3)/3; i++)
	{
		printf("%c", arr[i] - key);
	}
	printf("\n");
	
	// Освобождение массива
	free(arr);
	
	return 0;
}
