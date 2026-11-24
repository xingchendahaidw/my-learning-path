/*********************************
课堂笔记：2026-11-9
*********************************/
#include<stdio.h>

int getSum(int n);
int factorial(int );
int fibonacci( int n);
int reverseOrder(int n);
int greatestCommonDivisor(int m, int n);
void DecimalToBinary(int n);
int DecimalToBinary2(int n);

void printMenu(){
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
int getChoice(){
	int choice;
	printf("\nplease enter your choice:");
	scanf("%d",&choice);
	while(choice<0 || choice>7){
		printf("error! please enter again(0-7):");
		scanf("%d",&choice); 
	}
	return choice;
}
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
int factorial(int n) 
{
	int fac=1;
	for(int i=2; i<=n; i++) {
		fac *= i;
	}
	return fac;
}
long long fact(int n)
{
    // 递归终止条件
    if(n == 0 || n == 1)
        return 1;
    // 递推公式
    return n * fact(n - 1);
}

int getSum(int n) {
	int sum=0;
	for(int i=1; i<=n; i++) {
		sum += i;
	}
	return sum;
}

int fibonacci( int n){
	int f1 = 1;
	int f2 = 1;
	int temp=1;
	for(int i=3;i<=n;i++){
		temp = f1+f2;
		f1 = f2;
		f2 = temp;
	}
	return temp;
}

int reverseOrder(int n){
	int result=0;
	while(n!=0){
		result = result*10 + n%10;
		n /= 10;
	}
	return result;
}
int greatestCommonDivisor(int m, int n){
	int div=1;
	for(int i=1;i<=m && i<=n;i++){
		if(m%i==0 && n%i==0){
			div = i;
		}
	}	
	return div;
}

void DecimalToBinary(int n){
	printf("          ");//未处理0
	while(n!=0){
		printf("\b\b");//OJ上不好用，只能本地用
		printf("%d",n%2);
		n /=2;
	}
}
void DecimalToBinary(int n)//使用数组
{
    if (n == 0)
    {
        printf("0\n");
        return;
    }
    int buf[40];
    int idx = 0;
    while (n != 0)
    {
        buf[idx++] = n % 2;
        n /= 2;
    }
    // 逆序输出
    for (int i = idx - 1; i >= 0; i--)
    {
        printf("%d", buf[i]);
    }
    printf("\n");
}
void DecimalToBinary(int n)//使用递归方法
{
    if (n == 0)
    {
        return;
    }
    DecimalToBinary(n / 2);
    printf("%d", n % 2);
}
// 外层调用时单独处理0

int DecimalToBinary2(int n){
	int result=0;
	int level=1;
	if(n<0) return -1;
	while(n!=0){
		result +=  n%2 * level;
		n /= 2;
		level *= 10;
	}
	return result;
}
// 把二进制存入buf数组，返回字符串首地址
char* DecimalToBinary(int n, char* buf, int bufSize)
{
    int idx = bufSize - 1;
    buf[idx--] = '\0'; // 字符串结束符
    
    if (n == 0)
    {
        buf[idx--] = '0';
        return &buf[idx + 1];
    }
    
    unsigned int num = (unsigned int)n; // 处理无符号，避免负数问题
    while (num != 0 && idx >= 0)
    {
        buf[idx--] = (num % 2) ? '1' : '0';
        num /= 2;
    }
    return &buf[idx + 1];
}




