/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
 
#define int ll
 
const int N = 1000005, mod = 998244353;
int js[N], inv[N], a[N], n, k;
 
inline int Pow(int a, int b){
    int ans = 1;
    for(; b; b >>= 1, a = a * a % mod)
        if(b & 1) ans = ans * a % mod;
    return ans;
}
inline int C(int x, int y){
    return js[x] * inv[y] % mod * inv[x-y] % mod;
}
signed main(){
    js[0] = inv[0] = 1;
    for(int i = 1; i < N; i++)
        js[i] = js[i-1] * i % mod, inv[i] = Pow(js[i], mod - 2);
    int T; read(T);
    while(T--){
        read(n), k = 0;        
        for(int i = 1; i <= n; i++) read(a[i]), k += a[i];
        int ave = k / n, ned = 0, ans = 1;
        for(int i = 1; i <= n; i++){
            if(ned) (ans *= C(max(ave + ned, a[i]), ned)) %= mod;
            if(a[i] > ave + ned){
                (ans *= C(a[i] - ned, a[i] - ave - ned)) %= mod;
                a[i+1] += a[i] - ave - ned;
            }
            if(a[i] > ave) ned -= min(ned, a[i] - ave);
            else ned += ave - a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}