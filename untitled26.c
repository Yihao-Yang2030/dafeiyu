#include <stdio.h>
#include<stdlib.h>
int main()
{
	int *a=0;
	int num;
	int i;
	scanf("%d",&num);
	a=(int*)malloc(num*sizeof(int));
	for(i=0;i<num;i++)
	{
		a[i]=i;
	    printf("%d ",a[i]);}
	return 0;
}
