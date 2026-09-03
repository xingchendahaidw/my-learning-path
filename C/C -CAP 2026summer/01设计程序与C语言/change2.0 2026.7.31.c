#include<stdio.h>
//可以计算总金额不变的找零
int main()
{
	int price=0,AMOUNT=100;
	
	printf("请输入金额（元）：");
	scanf("%d",&price);
	int change=AMOUNT-price;
	printf("找您%d元。\n",change);
	
	return 0;
}
