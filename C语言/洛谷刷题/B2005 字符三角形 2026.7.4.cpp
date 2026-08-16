#include <stdio.h> 
int main(){
	char c;
	scanf("%c",&c);//输入，注意要取地址
    printf("  %c  \n",c);
    printf(" %c%c%c \n",c,c,c);
    printf("%c%c%c%c%c\n",c,c,c,c,c);
    return 0;
}
