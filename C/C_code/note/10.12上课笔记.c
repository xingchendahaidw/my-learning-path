#include<stdio.h>
int main1()
{
    int x;
    x=10;
    int y;
    y=x+20;
    int z=x+y;
    printf("%d\n",y);
    printf("%d\n",z);
    return 0;
}
int main2()
{
	int x,y,z;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	printf("%d+%d+%d=%d",x,y,z,x+y+z);
	return 0;
}
int main3()
{
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	
	printf("%d+%d=%d\n",x,y,x+y);
	printf("%d-%d=%d\n",x,y,x-y);
	printf("%d*%d=%d\n",x,y,x*y);
	printf("%d/%d=%d\n",x,y,x/y);
	printf("%d%%%d=%d\n",x,y,x%y);
	printf("sizeof int :%d\n",sizeof(x));
	printf("5/2=%.1f\n",5.0/2);
	return 0;
}
int main4()
{
	int x=0;
	printf("请输入一个三位数:\n"); 
	scanf("%d",&x);
	printf("%d\n",x%10);
	x=x/10;
	printf("%d\n",x%10);
	x=x/10;
	printf("%d\n",x%10);
}
int main5()
{
	int x=0;
	printf("请输入一个三位数：\n");
	scanf("%d",&x);
	printf("%d\n",x/100);
	x%=100;
	printf("%d\n",x/10);
	x%=10;
	printf("%d\n",x);
}
int main6()
{
	float x;
	double y;
	x=5.123456789;
	y=5.1234567891111;
	printf("%f\n",x);
	printf("%.12f",y);
	return 0;
}
int main7()
{
    char c;
    scanf("%c",&c);
    c=c-32;
    printf("%c",c);
    return 0;
}
int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	if(x>y)
	{
		printf("the max value is :%d\n",x);
	} else
	{
		printf("the max value is :%d\n",y);
	}
}



