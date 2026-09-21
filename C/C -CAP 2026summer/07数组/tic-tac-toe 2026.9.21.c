#include<stdio.h>
int main()
{
    const int size=3;
    int board[size][size];
    int i,j;
    int numOfX;
    int numOf0;
    int result=-1;//-1:没人赢，0：O赢，1：X赢

    //读入矩阵
    for ( i = 0; i < size; i++)
    {
        for ( j = 0; j <size; j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
    //检查行
    for ( i = 0; i <size&&result==-1; i++)
    {
        numOf0=numOfX=0;
        for ( j = 0; j < size; j++)
        {
            if (board[i][j]==1)
            {
                numOfX++;
            }else
            {
                numOf0++;
            }
        }
        if (numOf0==size)
        {
            result=0;
        }else if (numOfX==size)
        {
            result=1;
        }  
    }
    //检查列
    for ( i = 0; i <size&&result==-1; i++)
    {
        numOf0=numOfX=0;
        for ( j = 0; j < size; j++)
        {
            if (board[j][i]==1)
            {
                numOfX++;
            }else
            {
                numOf0++;
            }
        }
        if (numOf0==size)
        {
            result=0;
        }else if (numOfX==size)
        {
            result=1;
        }  
    }
    //检查对角线
    numOf0=numOfX=0;
    for ( i = 0; i <size; i++)
    {
        if(board[i][i]==1)
        {
            numOfX++;
        }else
        {
            numOf0++;
        }
    }
    if (numOf0==size)
    {
        result=0;
    }else if (numOfX==size)
    {
        result=1;
    }
    numOf0=numOfX=0;
    for ( i = 0; i < size; i++)
    {
        if (board[i][size-i-1]==1)
        {
            numOfX++;
        }else
        {
            numOf0++;
        }
    }
    return 0;
}