#include<stdio.h>
int main()
{
	int x,y;
	int a=0;
	scanf("%d%d",&x,&y);
	do{
		if(x%2==0)
		{
			a+=x;
		}
		x++;
	}while(x==y);
	printf("%d",a);
	return 0;
}
