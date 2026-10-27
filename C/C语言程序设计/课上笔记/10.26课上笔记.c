#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
int main1()
{
	char c;
	scanf("%c",&c);
	printf("%c\n",c);
	scanf("%d",&c);
	
	c=getchar();//单个字符的输入 
	putchar(c);//单个字符的输出 
	return 0;
}
int main2(){
	printf("  abc\rdef\n");
	printf("ddddfff\tabc\n");
	return 0;
} 
int main3()
{
	float y=10.1234;
	printf("%10.2f\n",y);
	printf("%-10.2f\n",y);
	int m,n;
	scanf("%d%d",&m,&n);
	return 0;
} 
int main4()
{
	int x;
	scanf("%d",&x);
	/*if(x>=90&&x<=100)printf("A");
	else if(x>=80)printf("B");
	else if(x>=70)printf("C");
	else if(x>=60)printf("D");
	else printf("E");*/ 
	int n=x/10;
	switch (x)
	{
		case(10):
		case(9):
			printf("A");
		break;
		case(8):
			printf("B");
		break;
		case(7):
			printf("C");
		break;
		case(6):
			printf("D");
		break;
		default: printf("E");
		return 0;
	} 
}
//简易计算器，switch语句
int main5(void)
{
    float data1, data2;
    char op;
    printf("Please enter an expression:");
    scanf("%f %c %f", &data1, &op, &data2);
    switch (op)
    {
        case '+':
            printf("%.2f+%.2f = %.2f\n", data1, data2, data1+data2);
            break;
        case '-':
            printf("%.2f-%.2f = %.2f\n", data1, data2, data1-data2);
            break;
        case '*':
        case 'x':
        case 'X':
            printf("%.2f*%.2f = %.2f\n", data1, data2, data1*data2);
            break;
        case '/':
            if (fabs(data2)<=1e-7)
                printf("Division by zero!\n");
            else
                printf("%.2f/%.2f = %.2f\n", data1, data2, data1/data2);
            break;
        default:
            printf("Invalid operator! \n");
        case '^':
            printf("%.2f^%.2f = %.2f\n", data1, data2, pow(data1,data2));
            break;
    }
    return 0;
}
int main6()//循环结构 
{
	int i=1;
	int cnt=0;
	for(;i<=100;i++)
	{
		if(i%2==0)
		{
			printf("%d\t",i);
			cnt++;
		}
		if(cnt%10==0)
		{
			printf("\n");
		}
	} 
	return 0;
}
int main7()
{
	int i=1;
	int cnt=0;
	for(;i<=2026;i++)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
		{
			printf("%d\t",i);
			cnt++;
			if(cnt%3==0)
		{
			printf("\n");
		}
		}
	}
	return 0;
}
int main8()
{
    int n,i;
    printf("Input n");
    scanf("%d",&n);
    int sum=0;
    for ( i = 1; i <=n; i++)
    {
        sum=sum+i;
    }
    printf("sum=%d\n",sum);
    return 0;
}
int main9()
{
	int x,i,j;
	int cnt[7]={0};
	scanf("%d",&x);
	srand(time(NULL));
	for(i=1;i<=x;i++)
	{
		
		int dice=rand()%6+1;
		cnt[dice]++;
	}
	for(j=1;j<=6;j++)
	{
		printf("%d:%d\n",j,cnt[j]);
	}
	return 0;
}
int star(int x)
{
	int i;
	for(i=1;i<=x;i++)
	{
		putchar('*');
	}
	printf("\n");
}
int main10()
{
	int i;
	for(i=1;i<=10;i++)
	{
		star(i);
	}
	for(i=10;i>=1;i--)
	{
		star(i);
	}
	return 0;
}
int main11()
{
	for(int i=0;i<10;i++)
	{
		for(int k=0;k<9-i;k++) putchar(' ');
		for(int j=1;j<=2*i+1;j++)
		{
			putchar('*');
		}
		printf("\n");
	 }
	for(int i=9;i>=0;i--)
	{
		for(int k=0;k<9-i;k++) putchar(' ');
		for(int j=1;j<=2*i+1;j++)
		{
			putchar('*');
		}
		printf("\n");
	 } 
}
int main12()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int x=i*j;
			printf("%d*%d=%d\t",i,j,x);
		}
		putchar('\n');
	}
	return 0;
}
int main()
{
	
}

