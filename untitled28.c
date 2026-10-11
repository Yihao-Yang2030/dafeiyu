#include <stdio.h>
#include<stdlib.h>
int main()
{
	int *a=0;
	int num;
	int i,b,c,e;
	scanf("%d",&num);
	a=(int*)malloc(num*sizeof(int));
	for(i=0;i<num;i++)
	{
		a[i]=1;
	}
	a[0]=a[1]=0;
	for(b=2;b<num;b++)
	{
		for(c=2;c<num;c++)
		{
			if(b*c<num){
			a[b*c]=0;}
		}
	}
	for(e=2;e<num;e++)
	{
		if(a[e])
		{
			printf("%d ",e);
		}
	}
	free(a);
	return 0;
}
