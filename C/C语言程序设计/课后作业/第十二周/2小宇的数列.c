#include<stdio.h>

int main()
{
    int arr[5];
    while(1)
    {
        for(int i=0;i<5;i++)
        {
            scanf("%d",&arr[i]);
        }
        if(arr[0]==0 && arr[1]==0 && arr[2]==0 && arr[3]==0 && arr[4]==0)
            break;

        int is_diff = 0;    
        int is_ratio = 0;   
        int is_fib = 0;     

        int d = arr[1] - arr[0];
        if(arr[2]-arr[1]==d && arr[3]-arr[2]==d && arr[4]-arr[3]==d)
        {
            is_diff = 1;
        }

        int q = arr[1] / arr[0];
        if(arr[0] != 0)
        {
            if( arr[1]==arr[0]*q && arr[2]==arr[1]*q && arr[3]==arr[2]*q && arr[4]==arr[3]*q )
            {
                is_ratio = 1;
            }
        }

        
        if(arr[2]==arr[0]+arr[1] && arr[3]==arr[1]+arr[2] && arr[4]==arr[2]+arr[3])
        {
            is_fib = 1;
        }

        if(is_diff)
        {
            printf("case one\n");
            int last = arr[4];
            for(int i=0;i<5;i++)
            {
                last += d;
                if(i>0) printf(" ");
                printf("%d", last);
            }
            printf("\n");
        }

        if(is_ratio)
        {
            printf("case two\n");
            int last = arr[4];
            for(int i=0;i<5;i++)
            {
                last *= q;
                if(i>0) printf(" ");
                printf("%d", last);
            }
            printf("\n");
        }

        if(is_fib)
        {
            printf("case three\n");
            int a = arr[3], b = arr[4];
            for(int i=0;i<5;i++)
            {
                int next = a + b;
                if(i>0) printf(" ");
                printf("%d", next);
                a = b;
                b = next;
            }
            printf("\n");
        }
    }
    return 0;
}