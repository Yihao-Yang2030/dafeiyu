#include<stdio.h>
int main()
{
	int m,n,i;
	int a=0;
	scanf("%d%d",&m,&n);
	if(m>n){
	for(i=n;i<=m;i++)
	{
		a+=i;
	}
	}else{
		for(i=m;i<=n;i++)
		{
			a+=i;
		}
	}
	printf("%d",a);
	return 0;
}
