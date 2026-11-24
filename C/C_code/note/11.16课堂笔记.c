#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int fac(int x);
int fac1(int x);
int fibonacci(int n);
int reverseOrder2(int num,int n);
int greatestCommonDivisor(int m,int n);
void DecimalToBinary(int n);
int DecimalToBinary1(int n);
int main1()
{
	int x,y;
	scanf("%d %d",&x,&y);
	
	printf("%d %d %d",x,y,DecimalToBinary1(x));
	return 0;
} 
int fac(int x)
{
	int fac=1;
	for(int i=1;i<=x;i++)
	{
		fac*=i;
	}
	return fac;
}
int fac1(int x)
{
	if(x==0||x==1)
	{
		return 1;
	}
	return x*fac1(x-1);
}
int fibonacci(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}
void reverseOrder(int num,int n)
{
	int flag=pow(10,n-1);
	if(num<10)
	{
		printf("%d",num);
	}else
	{
		reverseOrder(num%flag,n-1);
		printf("%d",num/flag);
	}
}
int reverseOrder2(int num,int n)
{
	int flag=pow(10,n-1);
	if(num<10)
	{
		return num;
	}
	return((num/flag)+reverseOrder2(num%flag,n-1)*10);
}
int greatestCommonDivisor(int m,int n)
{
	m=abs(m);
	n=abs(n);
	if(n==0)
	{
		return m;
	}
	return greatestCommonDivisor(n,m%n);
}
void DecimalToBinary(int n)
{
    if (n == 0)
    {
        return;
    }
    DecimalToBinary(n / 2);
    printf("%d", n % 2);
}
int DecimalToBinary1(int n)
{
	if(n==0)
	{
		return 0;
	}
	return n%2+DecimalToBinary1(n/2)*10;
}
void hanoi_recur(int n, char from, char aux, char to)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    // 1. 把n-1个盘子从起始柱移到辅助柱，借助目标柱
    hanoi_recur(n - 1, from, to, aux);
    // 2. 移动最底层的大盘，从起始柱到目标柱
    printf("Move disk %d from %c to %c\n", n, from, to);
    // 3. 把n-1个盘子从辅助柱移到目标柱，借助起始柱
    hanoi_recur(n - 1, aux, from, to);
}
int f1(int x)
{
	x=100;
	return 0;
}
int f2(int x)
{
	static int result=0;//static
	result +=0;
	return result;
}
int main2()
{
	int a=10;
	f1(a);
	printf("%d\n",a);
	int b;
	b=f2(a);
	//assert(a<10);
	printf("%d\n",b);
	b=f2(a);
	printf("%d\n",b);
	return 0;
}
int main3()
{
	int x,y,z;
	int arr[10];
	int arr1[5]={1,2,3,4,5};
	int arr2[5]={1,2,3};
	int arr3[]={1,2,3,4,5};
	int arr4[5]={0};
	int arr5[5]={1};
}
int main4()
{
	int score[5];
	for(int i=0;i<5;i++)
	{
		scanf("%d",&score[i]);
	}
	int sum=0;
	int max=score[0];
	for(int i=0;i<5;i++)
	{
		sum+=score[i];
		if(max<score[i])
		{
			max=score[i];
		}
	}
	double aver=1.0*sum/5;
	printf("%f",aver);
	printf("%d",max);
	return 0;
}
int main()
{
	int diceNumber[6]={0};
	srand(time(NULL));
	int dot;
	int sum=0;
	int n=10000000;
	for(int i=0;i<n;i++)
	{
		dot=rand()%6+1;
		diceNumber[dot-1]++;
		sum+=dot;
	}
	int aver=sum/n;
	double ans=0;
	for(int i=0;i<6;i++)
	{
		ans+=diceNumber[i]*pow(abs(aver-i-1),2);
	}
	ans/=n;
	ans=sqrt(ans);
	printf("%f",ans);
	return 0;
}





