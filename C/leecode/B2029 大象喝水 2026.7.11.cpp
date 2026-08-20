#include<stdio.h>
int main(){
	int a=0,b=0;
	int c=20000;
	scanf("%d %d",&a,&b);
	int d=c/(a*b*b*3.14);
	printf("%d",d+1);
	return 0;
}
