#include<stdio.h>
int main(){
	int x;
	int a;
	int b;
	int num=2;
	int i;
	scanf("%d",&x);
	b=x;
	do{
		b=b/(10*num);
		num++;
	}while(b!=0);
	//printf("%d ",num);
	b=x;
	//printf("%d的每一位数字是",x); 
	for(i=1;i<=num;i++){
		a=b/(10^(num-i));
		printf("%d ",a);
	}
	//printf("%d %d",a,b);
	return 0;
}
