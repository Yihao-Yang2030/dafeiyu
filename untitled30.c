#include<stdio.h>
int main()
{
	int I;
	int price=0;
	int i;
	scanf("%d",&I);
	i=I/100000;
	if(I>1000000)
	{
		price=(I-1000000)*1/100+39500;
	}else{
	switch (i)
	{
	case 10:
	case 9:
	case 8:
	case 7:
	case 6:
		price+=((I-600000)*1.5/100);
		I=600000;
	case 5:
	case 4:
		price+=((I-400000)*3.0/100);
		I=400000;
	case 3:
	case 2:
		price+=((I-200000)*5.0/100);
		I=200000;
	case 1:
		price+=((I-100000)*7.5/100);
		I=100000;
	case 0:
		price+=(I*10.0/100);
	}}
	printf("%d",price);
	return 0;
}
