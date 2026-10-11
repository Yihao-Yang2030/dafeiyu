#include<stdio.h>
int main()
{
	int m,n,i,t;
	scanf("%d%d",&m,&n);
	if(m<n)
	{
		t=m;
	    m=n;
		n=t;
	}
		for(i=n;i>=1;i--)
		{
			if(m%i==0&&n%i==0)
			{
				printf("%d",i);
				break;
			}
		}
		for(i=m;i<=m*n;i++)
		{
			if(i%m==0&&i%n==0)
			{
				printf("%d",i);
				break;
			}
		}
	return 0;
}
