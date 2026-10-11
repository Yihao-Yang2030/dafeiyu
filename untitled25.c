#include<stdio.h>
int num[101]={0};
int main()
{
	int i;
	int x;
	for(i=2;i<101;i++)
	{for(x=2;x<100;x++)
	{if(x*i<=100){
		num[x*i]=1;}
	}
	}
	int a;
	for(a=2;a<101;a++)
	{
	if(num[a]==0)
	{
		printf("%d ",a);
	}}
	return 0;
}
