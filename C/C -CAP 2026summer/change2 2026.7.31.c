#include<stdio.h>
int main()
{
	int price=0,AMOUNT=0;
	
	printf("�������ܼۺͽ�");
	scanf("%d %d",&AMOUNT,&price);
	int change=AMOUNT-price;
	printf("����%dԪ��\n",change);
	
	return 0;
}
