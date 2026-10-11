#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int number=rand()%100+1;
	int count=0;
	int guess;
	printf("请输入一个数字\n");
	do
	{
		scanf("%d",&guess);
		count+=1;
		if(guess>number)
		{
			printf("数字太大了\n");
		}
		else if(guess<number)
		{
			printf("数字太小了\n");
		}
	}while(guess!=number);
	printf("恭喜你，答对了,一共用了%d次/n",count);
	return 0;
}
