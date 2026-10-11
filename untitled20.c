#include<stdio.h>
int main()
{
	unsigned int t=1;
	int a=1;
	while(a<=32)
	{	t=t*2;
	    a++;}
	printf("%u",t);
	return 0;
}
