#include<stdio.h>
int main ()
{
	int a=6;
	int b=5;
	int t;
	t=a;
	a=b;
	b=t;
	printf("a=%d,b=%d\n",a,b);
	return 0;
}
