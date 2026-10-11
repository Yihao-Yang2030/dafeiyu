#include <stdio.h>
#include <stdlib.h>
int su(int x);
int main()
{
	int *a=0;
	int num;
	int i,b;
	scanf("%d",&num);
	a=(int*)malloc(num*sizeof(int));
	for(i=0;i<num;i++)
	{
		a[i]=i;
	}
	for(b=2;b<num;b++)
	{
		if(su(a[b]))
		{
			printf("%d ",b);
		}
	}
	free(a);
	return 0;
}
int su(int x)
{
	int isprime=1;
	int i;
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			isprime=0;
			break;
	}
}
	return isprime;
}
