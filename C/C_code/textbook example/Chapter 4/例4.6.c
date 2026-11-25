#include <stdio.h>
int main(void)
{
    int a;
    char b;
    float c;

    printf("Please input an integer:");
    scanf("%d", &a);
    printf("integer: %d\n", a);
    //getchar();
    printf("Please input a character:");
    scanf(" %c", &b);
    printf("character: %c\n", b);
    printf("Please input a float number:");
    scanf("%f", &c);
    printf("float: %f\n", c);

    return 0;
}
