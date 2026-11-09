#include<stdio.h>
int main()
{
	int n,i,j,h,k,l;
	scanf("%d",&n);
	h=n/2+1;
	for(i=1;i<=n;i++)
	{
		if(i<h)
		{
			for(j=1;j<=h-i;j++)
			{
				printf(" ");
			}
			for(k=1;k<=2*i-1;k++)
			{
				printf("*");
			}
		}
		else if(i==h)
		{for(l=1;l<=n;l++)
		{
			printf("*");
		}
		}
		else if(i>h)
		{
			for(j=1;j<=i-h;j++)
			{
				printf(" ");
			}
			for(k=1;k<=(n-i)*2+1;k++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}