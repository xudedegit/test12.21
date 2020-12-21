#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{
	int c,state;
	int sum=0;
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == IN)
			{
				int i = 0;
				for (i = 0; i < sum; i++)
				{
					printf("*");
				}
				printf("\n");
				state = OUT;
				sum = 0;
			}
		}
		else if (state == OUT)
		{
			state = IN;
			++sum;
		}
		else
		{
			++sum;
		}

	}

	return 0;

}