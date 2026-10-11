#include <stdio.h>
int main()
{
	int i=1;
	int x,y;
	scanf("%d",&x);
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			y=1;
			break;
		}}
		if(y==1)
		{
			printf("这不是一个素数");
		}
		else
		{
			printf("这是一个素数");
		}
	
	return 0;
}
