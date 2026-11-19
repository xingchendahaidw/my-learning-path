#include <stdio.h>

int main()
{
    int num[3];
    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    char order[4];
    scanf("%s", order);
    // 按指定顺序输出对应数值
    for (int i = 0; i < 3; i++)
    {
        if (i != 0)
            printf(" ");
        // 字符转下标：'A'→0（最小值），'B'→1（中间值），'C'→2（最大值）
        printf("%d", num[order[i] - 'A']);
    }
    printf("\n");
    return 0;
}
