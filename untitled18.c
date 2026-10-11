#include <stdio.h>
int main()
{
	int x,y,t;
	scanf("%d",&t);
	int m=1;
	x=t;
	while(t>9)
	{
		t=t/10;
		m=m*10;
	}
	while(m>0)
	{
		y=x/m;
		x=x%m;
		m=m/10;
		printf("%d",y);
		if(m>0)
		{
			printf(" ");
		}
	}
	return 0;
}
