#include <stdio.h>
#include <math.h>
//¼òÒ×¼ÆËãÆ÷£¬switchÓï¾ä
int main(void)
{
    float data1, data2;
    char op;
    printf("Please enter an expression:");
    scanf("%f %c %f", &data1, &op, &data2);
    switch (op)
    {
        case '+':
            printf("%.2f+%.2f = %.2f\n", data1, data2, data1+data2);
            break;
        case '-':
            printf("%.2f-%.2f = %.2f\n", data1, data2, data1-data2);
            break;
        case '*':
        case 'x':
        case 'X':
            printf("%.2f*%.2f = %.2f\n", data1, data2, data1*data2);
            break;
        case '/':
            if (fabs(data2)<=1e-7)
                printf("Division by zero!\n");
            else
                printf("%.2f/%.2f = %.2f\n", data1, data2, data1/data2);
            break;
        default:
            printf("Invalid operator! \n");
        case '^':
            printf("%.2f^%.2f = %.2f\n", data1, data2, pow(data1,data2));
            break;
    }
    return 0;
}