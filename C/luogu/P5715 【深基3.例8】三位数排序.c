#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    if(a>b){//½»»»
		int t;
		t=a;
		a=b;
		b=t;
	}
	if(a>c){//½»»»
		int t;
		t=a;
		a=c;
		c=t;
	}
	if(b>c){//½»»»
		int t;
		t=b;
		b=c;
		c=t;
	}
    printf("%d %d %d",a,b,c);
    return 0;
}