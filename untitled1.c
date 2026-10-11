#include <stdio.h>
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	if (N%K==0)
	printf("%d",N/K);
	else 
	printf("%d",N/K+1);
	return 0;
}
