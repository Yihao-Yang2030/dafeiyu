#include <stdio.h>
int main()
{
	int one,two,five;
	int x;
	printf("请输入多少元\n");
	scanf("%d",&x);
	for(one=0;one<=10*x;one++)
	{
		for(two=0;two<=5*x;two++)
		{
			for(five=0;five<=2*x;five++)
			{
				if(one+2*two+5*five==10*x)
				{
					printf("需要%d个一角,%d个两角,%d个五角\n",one,two,five);
					goto out;
				}
			}
		}
	}out:
	return 0;
}
