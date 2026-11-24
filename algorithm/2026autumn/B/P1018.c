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