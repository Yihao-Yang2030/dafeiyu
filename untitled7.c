#include <stdio.h>
int main()
{
	int x;
	int n=0;
	printf("请输入数字\n");
	scanf("%d",&x);
	n+=1;
	x/=10;
	while(x>0)
	{
		n+=1;
		x/=10;
	}
	printf("这是一个%d位数",n);
	return 0;
}
