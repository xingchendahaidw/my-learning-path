#include<stdio.h>
int main(){
	int x;
	int ret;
	scanf("%d",&x);
	int t=x;//小套路，保存原始数据 
	while(x>1){
		x/=2;
		ret++;
	}
	printf("log2 of %d is %d.",t,ret);
	return 0;
}
