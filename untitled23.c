#include <stdio.h>
int main()
{
	int num[10]={0};
	int i;
	scanf("%d",&i);
	while(i!=-1)
	{
		if(i>=0&&i<10){
		num[i]++;}
		else{printf("数字%d无效，请重新输入\n",i);}
		scanf("%d",&i);
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",num[i]);
	}
	return 0;
}
