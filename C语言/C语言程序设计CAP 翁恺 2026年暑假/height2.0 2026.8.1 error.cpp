#include<stdio.h>
int main(){
	printf("请分别输入身高的英尺和英寸，""如输入\"5 7\"表示5英尺7英寸：");
	int foot;
	int inch;
	scanf("%d %d",&foot,&inch);
	printf("身高是%f米。\n",((foot+inch/12)*0.3048));//注意整数运算和浮点运算的区别 
	return 0;
}
