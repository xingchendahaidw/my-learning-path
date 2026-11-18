#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long x[10005];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i] * (2LL * i - n + 1);
    }
    cout << sum << endl;
    return 0;
}
