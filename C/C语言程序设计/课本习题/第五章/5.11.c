#include <stdio.h>
int main()
{
    char sex, sports, diet;
    double faHeight, moHeight, height;

    printf("请输入性别(M男/F女)、父亲身高(cm)、母亲身高(cm)、是否运动(Y/N)、饮食是否良好(Y/N)：\n");
    // %c 前加空格，自动跳过换行、空格等空白字符
    scanf(" %c %lf %lf %c %c", &sex, &faHeight, &moHeight, &sports, &diet);

    // 计算基础身高
    if(sex == 'M' || sex == 'm')
        height = (faHeight + moHeight) * 0.54;
    else if(sex == 'F' || sex == 'f')
        height = (faHeight * 0.923 + moHeight) / 2;
    else
    {
        printf("性别输入错误！\n");
        return 0;
    }

    // 运动加成 +2%
    if(sports == 'Y' || sports == 'y')
        height *= 1.02;
    // 饮食加成 +1.5%
    if(diet == 'Y' || diet == 'y')
        height *= 1.015;

    printf("预测成年身高：%.2lf cm\n", height);
    return 0;
}
