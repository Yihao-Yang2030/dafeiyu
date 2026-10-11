#include <stdio.h>
int main()
{
	int number = 0;
	int count = 0;
	int sum;
	do{
		scanf("%d",&number);
		if(number!=-1){
			sum+=number;
			count+=1;
		}
	}while(number!=-1);
	printf("%f",1.0*sum/count);
	return 0;
}
