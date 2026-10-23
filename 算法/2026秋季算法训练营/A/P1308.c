#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000005 

char target[1000];
char article[MAX_LEN];

int main() {
    // 读取需要查找的单词
    if (scanf("%s", target) != 1) {
        return 0;
    }
    
    // 将目标单词全部转为小写，方便后续不区分大小写匹配
    int target_len = strlen(target);
    for (int i = 0; i < target_len; i++) {
        target[i] = tolower(target[i]);
    }

    //读取文章
    int c;
    // 跳过第一行末尾的换行符
    while ((c = getchar()) != '\n' && c != EOF); 

    int len = 0;
    // 逐字符读取文章内容，同时全部转为小写
    while ((c = getchar()) != '\n' && c != EOF) {
        article[len++] = tolower(c);
    }
    article[len] = '\0'; // 字符串结束符

    // 遍历文章，提取单词进行匹配
    int count = 0;       // 出现次数
    int first_pos = -1;  // 第一次出现的位置
    int i = 0;

    while (i < len) {
        // 跳过前面的空格
        while (i < len && article[i] == ' ') {
            i++;
        }
        if (i >= len) break; // 到达文章末尾

        // 记录当前单词的起始位置
        int start = i;
        
        // 寻找当前单词的结束位置
        while (i < len && article[i] != ' ') {
            i++;
        }
        int word_len = i - start; // 当前单词的长度

        // 判断是否为完全匹配
        if (word_len == target_len) {
            int match = 1;
            for (int j = 0; j < word_len; j++) {
                if (article[start + j] != target[j]) {
                    match = 0;
                    break;
                }
            }
            // 如果完全匹配
            if (match) {
                if (count == 0) {
                    first_pos = start; // 记录第一次出现的位置
                }
                count++;
            }
        }
    }
    // 输出结果
    if (count == 0) {
        printf("-1\n");
    } else {
        printf("%d %d\n", count, first_pos);
    }
    return 0;
}