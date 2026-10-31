#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int num, char* argv[])
{

	
	int *arr = (int *)malloc(num * sizeof(int));
	int k;

	for(int i = 1; i < num - 1; i++)
	{
		int num1, num2, res;
		num1 = atoi(argv[i-1]);
		num2 = atoi(argv[i+1]);
		if(strcmp(argv[i], "-k") == 0)
		{
			k = atoi(argv[i+1]);
			break;
		}
		
		switch(*argv[i])
		{
		case '+': res = num1 + num2; break;
                case '-': res = num1 - num2; break;
                case '*': res = num1 * num2; break;
                case '%': res = num1 % num2; break;
		}
		
		arr[i] = res;
		printf("%d\n", arr[i]);
	}
	
	for(int i = 2; i < num - 1; i+=3)
	{	
		printf("%c", arr[i] - k);
	}
	
	
	
	printf("\n");
	return 0;
}

//123 * 123 123 * 123 123 * 123 123 * 123 ...//
//1     3   4     6   7     9   10    12  ...//
//    2         5         8         11    ...//



