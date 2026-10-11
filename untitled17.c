#include<stdio.h>
int main()
{
	int i=1;
	int n;
	double sum=0.0;
	int sign=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=sign*1.0/i;
		sign=-sign;
	}printf("前%d项和为%f",n,sum);
	return 0;
}
