#include<bits/stdc++.h>
// #define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;

int T;
int n;
char s[maxn];

signed main(){
    T=read();
    while (T--){
        n=read();
        scanf("%s",s+1);
        int ans=n;
        int fst=-1,lst=-1;
        for (int i=1;i<=n;i++) if (s[i]=='1') {fst=i;break;}
        for (int i=n;i>=1;i--) if (s[i]=='1') {lst=i;break;}
        for (int i=1;i<=n;i++) if (s[i]=='1') ans=max(ans,max(i*2, max(((n-i+1)*2), i+(n-i+1))));
        if (fst!=-1 && fst!=lst) ans=max(ans, max(fst-1+(lst-fst+1)*2, (n-lst)+(lst-fst+1)*2));
        printf("%d\n",ans);
    }
    return 0;
}