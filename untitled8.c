#include <stdio.h>
int main()
{
	int x;
	int n=0;
	scanf("%d",&x);
	do
	{
		n+=1;
		x/=10;
	}while(x>0);
		printf("这是一个%d位数",n);
	return 0;
}
