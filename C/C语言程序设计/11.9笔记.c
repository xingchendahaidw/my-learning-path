#include<stdio.h>

void printMenu(); 
int getChoice();
int getSum(int n);
int factorial(int n);
int fibonacci(int n);
int reverseOrder(int n);
int greatestCommonDivisor(int m,int n);
void DecimalToBinary(int n);
int DecimalToBinary2(int n);
int main() {	
	int choice;
	int n=0;
	do{
		printMenu();
		choice = getChoice();
		if(choice!=0){		
			printf("please enter the number:");
			
			scanf("%d",&n);	
		}
		switch(choice) {
			case 1:				
				printf("1+2+...+%d = %d\n",n,getSum(n));
				break;
			case 2:
				printf("%d! = %d\n",n,factorial(n));
				break;
			case 3:
				printf("fibonacci(%d) = %d\n",n,fibonacci(n));
				break;
			case 4:
				printf("reverseOrder(%d) = %d\n",n,reverseOrder(n));
				break;
			case 5:
				printf("please enter the second number:");
				int a;
				scanf("%d",&a);
				printf("greatestCommonDivisor(%d,%d) = %d\n",
					   n,a,greatestCommonDivisor(n,a));
				break;
			case 6:
				DecimalToBinary(n);
				break;
			case 7:
				printf("DecimalToBinary2(%d) = %d\n",n,DecimalToBinary2(n));
				break;
		}
	}while(choice !=0);
}
void printMenu()
{
	printf("\n");
	printf("课堂笔记：2026-11-9\n");
	printf("1- 1+2+3+...+n\n");
	printf("2- n!\n");
	printf("3- fibonacci(n)\n");
	printf("4- reverseOrder(n)\n");
	printf("5- greatestCommonDivisor(int m, int n)\n");
	printf("6- DecimalToBinary(n)\n");
	printf("7- DecimalToBinary2(n)\n");
	printf("0- exit\n");
} 
int getChoice(int n)
{
	printf("Please enter your choice:");
	scanf("%d",&n);
	while(n<1||n>7)
	{
		printf("Please enter your choice(1-7):");
		scanf("%d",&n);
	}
	return n;
}
int getSum(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
	}
	/*while(n--)
	{
		sum+=n;
	}*/
	return sum;
}
int factorial(int n)
{
	int fac=1;
	for(int i=1;i<=n;i++)
	{
		fac*=i;
	}
	return fac;
}
int fibonacci(int n)
{
	int ans=1;
	int a1=1,a2=1;
	for(int i=3;i<=n;i++)
	{
		ans=a1+a2;
		a1=a2;
		a2=ans;
	}
	return ans;
}
int reverseOrder(int n)
{
	int x;
	while(n!=0)
	{
		x=x*10+n%10;//??
		n/=10;
	}
	return x;
}
int greatestCommonDivisor(int m,int n)
{
	int tmp=0;
	while(n!=0)
	{
		m=m%n;
		tmp=m;
		n=m;
		m=tmp;
	}
	return m;
}
void DecimalToBinary(int n)
{
	printf("           ");
	while(n!=0)
	{
		printf("\b\b");
		printf("%d",n%2);
		n/=2;
	}
}
int DecimalToBinary2(int n)//没写出来 
{
	int result =0;
	int level=1;
	while(n!=0)
	{
		result +=n%2*level;
		n/=2;
		level*=10;
	}
	return result;
}



