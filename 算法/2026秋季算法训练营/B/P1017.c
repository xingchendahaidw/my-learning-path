#include <stdio.h>

int binary_search_first(int a[], int n, int key) {
    int left = 0, right = n - 1;
    long long ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) {
            ans = mid;
            right = mid - 1;  // 继续向左找最小下标
        } else if (a[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (ans == -1)
        return -1;        // 找不到
    else
        return ans + 1;   
}

int main() {
    int n;
    scanf("%d", &n);
    int a[100005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int q;
    scanf("%d", &q);
    int qus[100005];
    for (int i = 0; i < q; i++) {
        long long key;
        scanf("%d", &key);
        qus[i] = binary_search_first(a, n, key);
    }
    for (int k = 0; k < q; k++) {  
        if (k > 0) printf(" ");
        printf("%d", qus[k]);
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <string.h>

char a[100005][65];
char key[65];

int cmp(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    return strcmp(s1, s2);
}

int main() {
    int n;

    if (scanf("%d", &n) != 1) return 0;


    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    int q;

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {

        scanf("%s", key);

        int left = 0;
        int right = n - 1;
        int ans = -1;


        while (left <= right) {
            int mid = left + (right - left) / 2;
            int c = cmp(a[mid], key);

            if (c == 0) {

                ans = mid + 1; 
                right = mid - 1; 
            } else if (c < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (i > 0) printf(" ");
        printf("%d", ans);
    }
    
    printf("\n");
    return 0;
}