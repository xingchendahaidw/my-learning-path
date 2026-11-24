#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h> 
int main1()//for循环复习,阶乘
{
	int n;
	int fac=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		fac*=i;
	}
	printf("%d",fac);
	return 0;
}
int main2()//while循环，计算位数 
{
	int x;
	scanf("%d",&x);
	int cnt=0;
	while(x!=0)
	{
		x/=10;
		cnt++;
	}
	printf("%d",cnt);
	return 0; 
}
int main3()//逆序三位数（优势：保存在一个变量中） 
{
	int x;
	scanf("%d",&x);
	int m=0;
	while(x!=0)
	{
		m=m*10+x%10;//核心语句 
		x/=10;
	}
	printf("%d\n",m);
	return 0;
}
int main4()//判断回文数1
{
	int x;
	scanf("%d",&x);
	int m=0;
	int n;
	n=x;
	while(n>=0)
	{
		m=m*10+x%10; 
		n/=10;
	}
	if(x==m)
	{
		printf("%d是回文数\n",x);
	}else
	{
		printf("%d不是回文数\n",x);
	} 
	return 0; 
} 
int main5()//判断回文数2 
{
    int n;
    scanf("%d", &n);
    
    int div = 1;
    // 先算出初始除数：让 div 变成 10^(位数-1)
    int temp = n;
    while (temp >= 10)
    {
        div *= 10;
        temp /= 10;
    }

    while (n >= 10)
    {
        int high = n / div;   // 取最高位
        int low = n % 10;     // 取最低位
        
        if (high != low)
            break;            // 首尾不等，直接不是回文
        
        // 去掉首尾两位
        n = (n % div) / 10;
        div /= 100;           // 除数同步缩小100倍
    }
    
    if (n < 10)
        printf("Yes.");
    else
        printf("No.");
    
    return 0;
}
int main6()
{
	int sum;
	for(int j=2;j<=10000;j++)
	{
		sum=1;
		for(int i=2;i<sqrt(j);i++)
		{
			if(j%i==0)
			{
				sum=sum+i+(j/i);
			}
		}
		if(sum==j)
		{
			printf("%d\t",j);
		}
	}
	return 0;
}
int main7()//枚举法求最大公约数 
{
    int a,b;
    int min;

    scanf("%d,%d",&a,&b);
    if(a<b)
    {
        min=a;
    }else
    {
        min=b;
    }
    int ret=0;
    int i;
    for ( i = 1; i <min; i++)
    {
        if (a%i==0)
        {
            if (b%i==0)
            {
                ret=1;
            }
        }
    }
    printf("%d和%d的最大公约数是%d\n",a,b,ret);
    return 0;
}
int main8()//辗转相除法求最大公约数 
{
    int a,b;
    int t;

    scanf("%d %d",&a,&b);
    int orga;
    int orgb;
    while (b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    printf("%d和%d的最大公约数是%d。\n",orga,orgb,a);
    return 0;
}
int main9()//求e 
{
	double sum;
	double t;
	for(int i=0;i<=10000;i++)
	{
		t=1;
		for(int j=2;j<=i;j++)
		{
			t*=1.0/j;
		}
		sum+=t;
	}
	printf("%.12f",sum);
	return 0;
}
int main10()//更改后的 
{
    double sum = 0.0;   // 必须初始化！原代码这里是bug
    double term = 1.0;  // 初始项：1/0! = 1
    
    sum += term;        // 先加上 i=0 的项
    for(int i = 1; i <= 10000; i++)
    {
        term /= i;      // 递推：1/i! = 1/(i-1)! / i
        sum += term;    // 累加到总和
    }
    
    printf("%.12f\n", sum);
    return 0;
}
int main12()//向后移动5个字符，逐个读取字符 
{
    char ch;
    // 逐个读取字符，直到读到换行符结束
    while ((ch = getchar()) != '\n')//重点 
    {
        // 处理小写字母：后移5位，循环
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + 5) % 26 + 'a';
        }
        // 处理大写字母：后移5位，循环
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + 5) % 26 + 'A';
        }
        // 非字母（数字、空格、符号等）不处理，直接输出
        putchar(ch);
    }
    putchar('\n'); // 输出换行，保证结果单独占一行
    return 0;
}
int main13()//解码 
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        // 小写字母前移5位，循环
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' - 5 + 26) % 26 + 'a';
        }
        // 大写字母前移5位，循环
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' - 5 + 26) % 26 + 'A';
        }
        // 非字母原样输出
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
int main14()
{
    int magic;      // 计算机"想"的数
    int guess;      // 用户猜的数
    int counter=0;
    int ret;
    srand(time(NULL));
    magic = rand()%100+1; // 调用随机函数"想"一个数 magic
    do
    {
        
        ret=scanf("%d", &guess);  // 输入用户猜的数 guess
        while (ret!=1)
        {
            while (getchar()!='\n')
            {
                printf("Please guess a magic number:");
                ret=scanf("%d", &guess);
            }
        }
        counter++;
        if (guess > magic)
            printf("Wrong! Too big!\n");
        else if (guess < magic)
            printf("Wrong! Too small!\n");
        else
            printf("Right!\n");
    } while (guess!=magic&&counter<10);
    printf("%d",counter); 
    return 0;
}
int main15()
{
    int input;
    scanf("%d",&input);
    int i,j;
    int isPrime=1;
    int cnt=0;
    for ( i=2;cnt<=input; i++)
    {
        isPrime=1;
        for ( j=2; j<i; j++)
    {
        if (i%j==0)
        {
            isPrime=0;
            continue;
        }
        
    }
        if(isPrime==1)
        {
            printf("%d\t",i);
        }
    }
    return 0;
}