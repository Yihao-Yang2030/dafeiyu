#include <stdio.h>
int main()
{
	int i,y;
	int g=0;
	int x=2;
	scanf("%d",&y);
	while(x<=y)
	{
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
				g=1;
				break;
			}
		}
		if(g==0)
		{
			printf("%d ",x);
		}
		x++;
		g=0;
	}
	return 0;
}
