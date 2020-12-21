#include <stdio.h>
#define MAXHIST 15      //直方图最大的长度
#define MAXWORD 11      //一个单词最大的长度
#define IN 1   //在单词中
#define OUT 0  //在单词外

int main()
{
	int c;
	int i;
	int nc;   //一个单词的字符长度
	int state;
	int len;
	int maxvalue;
	int ovflow;   //大于单词最大长度的部分
	int wl[MAXWORD];
	state = OUT;
	nc = 0;
	ovflow = 0;
	for (i = 0; i < MAXWORD; ++i)
	{
		wl[i] = 0;
	}
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			if (nc > 0)
				if (nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			nc = 0;
		}
		else if (state == OUT)
		{
			state = IN;
			nc = 1;
		}
		else
			++nc;
	}
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
	{
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
	}
	for (i = 1; i < MAXWORD; ++i)
	{
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0)
		{
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;
		while (len > 0)
		{
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (ovflow > 0)
		printf("there are %d words >= %d \n", ovflow, MAXWORD);
	return 0;

}