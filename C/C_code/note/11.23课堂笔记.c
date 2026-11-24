/******************************/
/*     课堂笔记2026-11-23     */
/******************************/ 
#include<stdio.h>
#include<string.h>
int main1()
{
	int arr[5]={1,2,3,4,5};
	int b[5];
	memset(arr,0,sizeof(arr));
	printf("%d\n",arr[0]);
	return 0;
	arr[0]=1;
	b[0]=10;
	memcpy(b,arr,sizeof(arr));
	printf("%d\n",b[0]);
} 
#define  MONTHS 12
int main2()
{
    int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month;
    do{
        printf("Input a month:");
        scanf("%d", &month);
    }while(month < 1 || month > 12);  /* 处理不合法数据的输入 */
    printf("The number of days is %d\n", days[month-1]);
    return 0;
}
int main3()
{
    int days[2][MONTHS] = {{31,28,31,30,31,30,31,31,30,31,30,31},
                      {31,29,31,30,31,30,31,31,30,31,30,31}};
    int year, month;
    do{
        printf("Input year,month:");
        scanf("%d,%d", &year, &month);
    }while (month < 1 || month > 12);   
    if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
        printf("The number of days is %d\n", days[1][month-1]);
    else 
        printf("The number of days is %d\n", days[0][month-1]);
    return 0;
}
int main4()
{
    int days[2][MONTHS] = {{31,28,31,30,31,30,31,31,30,31,30,31},
                      {31,29,31,30,31,30,31,31,30,31,30,31}};
    int year, month,day;
    do{
        printf("Input year,month,day:");
        scanf("%d %d %d", &year, &month,&day);
    }while (month < 1 || month > 12);
	int isLeap=0;   
    if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
        isLeap=0;
    int sum=0;
    for(int i=0;i<month-1;i++)
    {
    	sum+=days[isLeap][i];
	}
	sum+=day;
	printf("%d",sum);
    return 0;
}
#include<stdlib.h>
#include<time.h>
void exchangeSort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }                    
        }
    }    
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++) printf("%3d",arr[i]);
    puts("");
}
void selectionSort(int arr[],int n){
    int index,temp;
    for(int i=0;i<n-1;i++){
        index = i;
        for(int j=i+1;j<n;j++){
            if(arr[index]>arr[j]) index = j;                            
        }
        if(index != i){
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }    
    }    
}
void bubbleSort(int arr[],int n){
    int index,temp;
    for(int i=0;i<n-1;i++){        
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }                        
        }
    }    
}

void insertSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++){
        temp = arr[i];  
        j = i - 1;      

        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int search(int arr[],int n,int x){
    int index = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == x) {
            index = i; 
            break;
        }
    }
    return index;
}

int binarySearch(int arr[],int n,int x){
    int left = 0;
    int right = n-1;
    int mid;    
    mid = (left + right)/2;
    while(left<=right){
        if(arr[mid] == x) return mid;
        else if (arr[mid]<x){
            left = mid+1;
        }else if(arr[mid]>x){
            right = mid-1;
        }
        mid = (left + right)/2; 
    }
    return -1;    
}
int main5(){
    int arr[10];
    int temp;
    srand(time(NULL));
    for(int i=0;i<10;i++) arr[i] = rand()%100;
    printArray(arr,10);
    printf("1-交换法排序（Exchange Sort）\n");
    printf("2-选择法排序（Selection Sort）\n");
    printf("3-冒泡排序（Bubble Sort）\n");
    printf("4-插入排序（Insertion Sort）\n");
    printf("5-顺序查找\n");
    printf("6-折半查找\n");
    int choice=0;
    printf("please enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1: exchangeSort(arr,10);break;    
        case 2:selectionSort(arr,10);break;    
        case 3:bubbleSort(arr,10);break;    
        case 4:insertSort(arr,10);break;
        case 5:
            printf("please enter the number you want to search:");
            int x,index;
            scanf("%d",&x);
            index = search(arr,10,x);
            if(index == -1) printf("cannot find %d\n",x);
            else printf("find %d at position %d\n",x,index);
            break;
        case 6:
            printf("please enter the number you want to search:");
            
            scanf("%d",&x);
            bubbleSort(arr,10);
            index = binarySearch(arr,10,x);
            if(index == -1) printf("cannot find %d\n",x);
            else printf("find %d at position %d\n",x,index);
    } 
    printArray(arr,10);
}
void print2Array(int arr[][3],int nrow,int ncol){
    for(int i=0;i<nrow;i++){
        for(int j=0;j<ncol;j++){
            printf("%3d",arr[i][j]);
        }
        puts("");        
    }
}
void transpose2Array(int arr[][3],int nrow,int ncol){
    for(int i=0;i<nrow;i++){
        for(int j=0;j<ncol;j++){
            printf("%3d",arr[j][i]);
        }
        puts("");        
    }
}
void printDiagonal(int arr[][3],int nrow,int ncol){
    for(int i=0;i<nrow;i++){        
        printf("%3d",arr[i][i]);
    }
    puts("");
}
void printSpiral(int arr[][3],int nrow,int ncol){
    int row,col;
    
    for(int i=0;i<nrow;i++){
        row = 0;
        col = i;
        while(row<=2){
            printf("%3d",arr[row][col]);
            row++;
            col++;
            if(col>2) col=0;             
        }    
        puts("");
    }
    puts("");
}
void addMatrix(int arr[][3],int arr2[][3],int arr3[][3],int nrow,int ncol){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr3[i][j] = arr[i][j] + arr2[i][j];
        }
    }
}
void multiplyMatrix(int arr[][3],int arr2[][3],int arr3[][3],int nrow,int ncol){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr3[i][j] = 0 ;
            for(int k=0;k<ncol;k++){
                arr3[i][j] += arr[i][k] * arr2[k][j];
            } 
        }
    }
}
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int arr2[3][3]={11,22,33,44,55,66,77,88,99};
    int arr3[3][3];
    printf("1-二维数组输出\n");
    printf("2-二维数组的转置\n");
    printf("3-输出对角线\n");
    printf("4-螺旋输出\n");
    printf("5-矩阵相加\n");
    printf("6-矩阵相乘\n");
    int choice=0;
    printf("please enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:print2Array(arr,3,3);break;    
        case 2:transpose2Array(arr,3,3);break;    
        case 3:printDiagonal(arr,3,3);break;    
        case 4:printSpiral(arr,3,3);break;
        case 5:addMatrix(arr,arr2,arr3,3,3);break;
        case 6:multiplyMatrix(arr,arr2,arr3,3,3);break;    
    } 
}
void magicSquare(int arr[][7],int n){
    int row=0;
    int col=n/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    for(int i=1;i<=n*n;i++){
        arr[row][col] = i;
        row--;
        col++;
        if(row<0) row=n-1;
        if(col>n-1) col=0;
        if(row<0 && col>n-1){
            row += 2;
            col--;
        }
        if(arr[row][col] != 0){
            row += 2;
            col--;
        }        
    }
}



