#include<stdio.h>
int main()
{
	int k;
	int a=0;
	int b=0;
	double c=0.0;
	for(k=1;k<=100;k++)
	{
		a+=k;
	}
	for(k=1;k<=50;k++)
	{
		b+=k*k;
	}
	for(k=1;k<=10;k++)
	{
		c+=(1.0/k);
	}
	printf("%.2f",a+b+c);
	return 0;
}
