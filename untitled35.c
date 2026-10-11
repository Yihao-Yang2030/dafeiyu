#include<stdio.h>
int main()
{
	int n,i;
	int first=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%3==0||i%4==0)
		{
			if(first==1){
				printf("%d",i);
			}else {
				printf(" %d",i);}
			first=0;
		}
	}
	return 0;
}
