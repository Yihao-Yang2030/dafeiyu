#include<stdio.h>
int main()
{
	int number[100];
	int cet=0;
	int i=0;
	int x;
	int sum=0;
	double average=0.0;
	//int average=0;
	scanf("%d",&x);
	while(x!=-1)
	{
		 number[cet]=x;
		sum+=x;
		cet++;
		scanf("%d",&x);
	}average=1.0*sum/cet;
	printf("%.2f\n",average);
	//printf("%d",average);
	for(i=0;i<cet;i++)
	{
		if(number[i]>average)
		{
			printf("%d\n",number[i]);
		}
	}return 0;
}
