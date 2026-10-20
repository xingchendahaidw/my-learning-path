#include<iostream>
using namespace std;
/*int main1()//数组
{
1.数据类型 数据名[数组长度]；
2.数据类型 数组名[数组长度]={值1，值2，值3……}；
3.数据类型 数组名[]={值1，值2……}；

//1.数据类型 数据名[数组长度]；
//int arr[5];
//给数组中元素赋值
//arr[0]=10;
//arr[1]=20;
//arr[2]=30;
//arr[3]=40;
//arr[4]=50;
//cout<<arr[0]<<endl;
//cout<<arr[1]<<endl;
//cout<<arr[2]<<endl;
//cout<<arr[3]<<endl;
//cout<<arr[4]<<endl;
//2.数据类型 数组名[数组长度]={值1，值2，值3……}；
//0填补，如果初始化时未赋值；
    int arr2[5]={10,20,30,40};
    for (int i = 0; i <5; i++)
{
    cout<<arr2[i]<<endl;
}
//3.数据类型 数组名[]={值1，值2……};
int arr3[]={90,80,70,60,50,40,30,20,10};
int arr2[5]={10,20,30,40};
    for (int i = 0; i <5; i++)
{
    cout<<arr2[i]<<endl;
}
}
int main()//一维数组
{
    //数组名的用途
    //1。可以通过数组名统计整个数组占用内存大小
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    //2、可以通过数组名查看数组首地址
    cout <<(int)arr<<endl;
    cout<<(int)&arr[0]<<endl;
    //数组名时常量，不可以进行赋值操作
}
int main()//练习1
{
    int arr[5]={300,350,200,400,250};
    int max=0;
    for (int  i = 0; i <5; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<max<<endl;
}
int main()//练习2:元素逆置
{
    int arr[5]={1,3,2,5,4};
    cout<<"数组逆置前"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
    int start=0;
    int end=sizeof(arr)/sizeof(arr[0])-1;
    while (start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
}*/
int main()//冒泡排序
{
    int arr[9]={4,2,8,0,5,7,1,3,9};
    cout<<"排序前："<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout <<endl;
    //开始冒泡排序
    //总排序轮次为 元素个数-1
    for (int  i = 0; i <9-1; i++)
    {
        //内层循环对比 次数= 元素个数-当前轮数-1
        for (int j = 0; j <9-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //排序后结果
    cout<<"排序后："<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout <<endl;

}