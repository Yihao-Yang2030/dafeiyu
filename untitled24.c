#include <stdio.h>
int num[100];
int arrive(int x);
int main()
{
	int a=0;
	for(a=0;a<101;a++)
	{
		num[a]=a;
	}for(a=2;a<101;a++)
	{
	if(arrive(a))
	{
		printf("%d ",a);
	}}
	return 0;
}
int arrive(int x)
{
	int isprime;
	int i;
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			isprime=0;
			break;
		}else{isprime=1;}
	}return isprime;
	
}
