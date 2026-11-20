#include<stdio.h>
int main()//第二题 
{
	int m,n;
	scanf("%d %d",&m,&n);
	
	if(m%n==0)
	{
		printf("YES");
	}else
	{
		printf("NO");
	}
	return 0;
 } 
int main()//第三题
{
	int year;
	scanf("%d",&year);
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		printf("yes");
	}else 
	{
		printf("no");
	}
	return 0;
}
int main()
{
	int a,x,b;
	scanf("%d %d %d",&a,&x,&b);
	printf("%d",a*x+b);
	return 0;
}
