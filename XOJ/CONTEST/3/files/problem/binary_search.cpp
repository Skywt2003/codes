#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int a[MAXN];
int n;
void bs(int x) {
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            printf("%d found\n", x);
            return;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d not found\n", x);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int q;
    scanf("%d", &q);
    while(q--) {
        int x;
        scanf("%d", &x);
        bs(x);
    }
    return 0;
}
