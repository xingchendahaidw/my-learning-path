#include<stdio.h>
//输入年份和月份，输出月份天数
int main()
{
    int y,m;
    scanf("%d %d",&y,&m);

    int day;
    switch (m)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        day=31;
        break;
    case 4 :case 6:case 9:case 11:
        day=30;
        break;
    case 2:
        if((y%4==0&&y%100!=0)||y%400==0)
        {
            day=29;
        } else 
        {
            day=28;
        }
        break;
    }
    printf("%d",day);
    return 0;
}
//题解优秀作品
#include <bits/stdc++.h>
using namespace std;

int y, m;
int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//做成数表的存储形式比较简洁
bool check(int year) {
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int main() {
	cin >> y >> m;
	if (check(y)) a[2] = 29;
	cout << a[m];
	return 0;
}
