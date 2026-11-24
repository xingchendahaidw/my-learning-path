#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string target, article;

    // 读取单词
   cin >> target;
    
    char c;
    while (cin.get(c) && c != '\n');

    //读取文章
    getline(cin, article);

    // 将目标单词和文章全部转为小写，实现不区分大小写
    for (char &ch : target) ch = tolower(ch);
    for (char &ch : article) ch = tolower(ch);

    int count = 0;       // 出现次数
    int first_pos = -1;  // 第一次出现的位置
    int len = article.length();
    int i = 0;

    //遍历文章，提取单词
    while (i < len) {
        // 跳过空格
        while (i < len && article[i] == ' ') i++;
        if (i >= len) break;

        // 记录单词起始位置
        int start = i;
        
        // 找到单词结束位置
        while (i < len && article[i] != ' ') i++;
        int word_len = i - start;

        //提取当前单词并比较
        if (word_len == target.length()) {
            string current_word = article.substr(start, word_len);
            if (current_word == target) {
                if (count == 0) {
                    first_pos = start; // 记录首次出现的位置
                }
                count++;
            }
        }
    }

    if (count == 0) {
        cout << -1 << endl;
    } else {
        cout << count << " " << first_pos << endl;
    }

    return 0;
}