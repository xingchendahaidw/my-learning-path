#include<stdio.h>
int main() {
    char s[14]; // ISBN 号码最多 13 字符 + 1 结束符
    scanf("%s", s);

    int sum = 0, cnt = 1; // sum 为加权和，cnt 为当前权重
    for (int i = 0; i < 11; i++) {
        if (s[i] == '-') continue; // 跳过分隔符
        sum += (s[i] - '0') * cnt++; // 加权累加
    }

    char check = (sum % 11 == 10) ? 'X' : (sum % 11 + '0'); // 计算识别码
    if (check == s[12]) {
        puts("Right"); // 识别码正确
    } else {
        s[12] = check; // 修正识别码
        puts(s); // 输出正确的 ISBN 号码
    }

    return 0;
}
