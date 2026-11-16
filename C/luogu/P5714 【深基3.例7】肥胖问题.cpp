#include <bits/stdc++.h>
using namespace std;

int main() {
    double z,m,h;
    cin >> m >> h;
    z = (m /(h * h));
    if (z < 18.5) cout << "Underweight";
    else if (z >= 18.5 && z < 24) cout << "Normal";
    else cout << z << endl << "Overweight";
    return 0;
    
}