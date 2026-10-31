#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char* argv[])
{
	int *arr = (int *)malloc((argc-3)/3 * sizeof(int));
	int k;
	bool s = true;

	for(int i = 2;i < argc; i += 3)
	{	

		if((argv[i-1][0] == '-') && (argv[i-1][1] == 'k'))
		{
			k = atoi(argv[i]);
			break;
		}

		int num1 = atoi(argv[i-1]), num2 = atoi(argv[i+1]), res;
		
		printf("%d %d\n", num1,num2);
		switch(argv[i][0])
		{
		case '+': res = num1 + num2; break;
                case '-': res = num1 - num2; break;
                case '*': res = num1 * num2; break;
                case '%': res = num1 % num2; break;
		default: printf("Неккоректный оператор: %c\n", argv[i][0]); s = false; break;
		}
		arr[i/3] = res;
	}

	if(!s)
	{
		return 1;
	}

	for(int i = 0; i < (argc-3)/3; i++)
	{
		printf("%c", arr[i] - k);
	}
	printf("\n");
	free(arr);
	return 0;
}


