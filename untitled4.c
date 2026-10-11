#include <stdio.h>
int main()
{
int price=0;
int amount=0;
printf("请输入金额,票面");
scanf("%d %d",&price,&amount);
if(price>amount)
printf("您还需要付%d元钱",price-amount);
else
printf("应该找您%d元钱",amount-price);
return 0;
}
