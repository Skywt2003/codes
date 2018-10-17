#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
  
const LL INF = 1e18;
  
LL ans = INF, s, t, a, b, f[150];
  
namespace {
    template <typename T> inline void read(T &x) {
        x = 0; T f = 1; char c = getchar();
        for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
        for(;  isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
        x = x * f;
    }
}
int main() {
    read(s), read(t), read(a), read(b);
    if(s == t) return 0 * printf("0\n");
    if(!a && !b) {
        if(!t) return 0 * printf("1\n");
        else return 0 * printf("-1");
    } else if(!a && b) {
        if((a == 0 && b == 1) || !s) return 0 * printf("-1");
        for(LL mul = 1, tim = 0; s * mul <= t; mul *= b, tim ++) {
            if(s * mul == t) ans = min(ans, tim);
        }
        printf("%lld\n", (ans == 1e18) ? -1 : ans);
    } else if(a && !b) {
        if(t >= s && (t - s) % a == 0) return 0 * printf("%lld\n", (t - s) / a);
        if(t % a == 0) return 0 * printf("%lld\n", t / a + 1);
        printf("-1\n");
    } else {
        int flag = 0;
        if(b == 1) {
            if((t - s) % a == 0 && t >= s) return 0 * printf("%lld\n", (t - s) / a);
            else return 0 * printf("-1\n");
        } else if(!s) {
            s += a, flag = 1;
        }
        for(LL mul = 1, tim = 0; s * mul <= t; mul *= b, tim++) {
            LL res = tim, del = t - s * mul;
            f[tim] = mul;
            if(del % a) continue;
            del /= a;
            for(int i = tim; ~i; --i) {
                res += del / f[i];
                del %= f[i];
            }
            ans = min(ans, res);
        }
        printf("%lld\n", (ans == 1e18) ? -1 : ans + flag);
    }
    return 0;
}