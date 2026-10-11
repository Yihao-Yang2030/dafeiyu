#include<stdio.h>
int main()
{
	
	int score,i;
	scanf("%d",&score);
	while(score!=-1){
	if(score>100||score<0)
	{
		printf("错误\n");
	}else{
	i=score/10;
	switch (i){
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	default:
		printf("E\n");
	}}
	scanf("%d",&score);
	}
	return 0;
}
