#include <stdio.h>
#include <math.h>//要包括这个数据库才可以执行sqrt函数 
int main(){
	double a=0,b=0,c=0;
	scanf("%lf %lf %lf",&a,&b,&c);
	double p=(a+b+c)/2;
	double s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",s);
	return 0;
}
