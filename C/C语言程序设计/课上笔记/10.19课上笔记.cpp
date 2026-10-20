#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main1()
{
	int a=0;
	a=10;
	a=20*10;
	return 0;
} 
int main2()
{
	int x;
	srand(time(NULL));
	x=rand();
	printf("%d\n",x%10);
	printf("%d\n",x%27+53); //53-83
	return 0;
}
int main3()
{
	int a,b;
	a=10;
	
	a=a+20;
	a+=20;
	a++;
	++a;
	a=10;
	b=5;
	b=b+++a;
	printf("%d",b);
	return 0;
}
#define PI 3.14159
int main4()
{
	float l,a;
	float r=5.3;
	a=PI*r*r;
	l=PI*2*r;
	printf("%f\n",l);
	printf("%f\n",a);
	return 0;
}
#include<math.h>
int main5()
{
	float a,b,c;
	scanf("%f %f %f",&a,&b,&c);
	float p=0.5*(a+b+c);
	float s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%f",s);
	return 0;
}
int main6()
{
	int a=10;
	printf("%d",10<20);
	if(a==0)
	{
		printf("a");
	} else
	{
		printf("b");
	}
}
int main7()
{
	int a,b,max;
	scanf("%d %d",&a,&b);
	/*if(a>b)
	{
		max=a;
	} else
	{
		if(a<=b)
		{
			max=b;
		}
	}*/
	if(a>b)
	{
		max=a;
	} else
	{
		max=b;
	}
	printf("%d",max);
	return 0;
}
int main8()
{
	int a,max;
	scanf("%d",&a);
	max=a;
	scanf("%d",&a);
	if(a>max)
	{
		max=a;
	}
	scanf("%d",&a);
	if(a>max)
	{
		max=a;
	}
	printf("%d",max);
	return 0;
}
int main9()
{
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
		{
			max=a;
		}
		
	}else
	{
		if(b>a)
		{
			if(b>c)
			{
			max=b;
			}
		} else
		{
			if(c>a)
			{
				if(c>b)
				{
					max=c;
				}
			} 
		}
	} 
	
	printf("%d",max);
}
int main10 ()
{
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b&&a>c)
	{
		max=a;
	}else
	{
		if(b>a&&b>c)
		{
			max=b;
		}else
		{
			if(c>a&&c>b)
			{
				max=c;
			}
		}
	}
	printf("%d",max);
	return 0;
}
int main11()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int max=a;
	int tri=1;
	if(b>max)
	{
		max=b;
	}
	if(c>max)
	{
		max=c;
	}
	if(a+b<max||b+c<max||a+c<max)
	{
		tri=0;
	}
	if(tri==1)
	{
		printf("yes");
	}else
	{
		printf("no");
	}
}
int main12()
{
	char a;
	scanf("%c",&a);
	if(a<=90)
	{
		printf("ด๓ะด"); 
	}else
	{
		printf("ะกะด");
	}
}
int main()
{
	int year;
	scanf("%d",&year);
	if(year%400==0)
	{
		printf("yes\n");
	}else
	{
		if(year%4==0&&year%100!=0)
		{
			printf("yes\n");
		}else
		{
		printf("No\n");
		}
	}
}




