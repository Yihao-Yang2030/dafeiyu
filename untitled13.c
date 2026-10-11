#include <stdio.h>
int main()
{
	int x=1;
	int n;
	int y=1;
	scanf("%d",&n);
	while(x<=n)
	{
		y=y*x;
		x+=1;
	}
	printf("%d",y);
	return 0;
}
