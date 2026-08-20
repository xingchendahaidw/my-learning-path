#include<stdio.h>
int main(){
	int price=0,AMOUNT=0;
	printf("请输入总价和金额：");
	scanf("%d %d",&AMOUNT,&price);
	int change=AMOUNT-price;
	printf("找您%d元。\n",change);
	return 0;
}
