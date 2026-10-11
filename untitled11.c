#include <stdio.h>
int main()
{
	int x,digit;
	scanf("%d",&x);
	while(x>0)
	{
		digit=x%10;
		printf("%d",digit);
		x/=10;
	}
	return 0;
}
