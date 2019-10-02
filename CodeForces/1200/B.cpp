#include<bits/stdc++.h>
using namespace std;

// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105;

int T;
int n,m,k;
int h[maxn];

signed main(){
    T=read();
    while (T--){
        n=read(); m=read(); k=read();
        for (int i=1;i<=n;i++) h[i]=read();
        for (int i=1;i<n;i++){
            if (h[i] < max(0,h[i+1]-k)){
                if (max(0,h[i+1]-k)-h[i] > m){
                    printf("NO\n");
                    m=-1;
                    break;
                }
                m-=max(0,h[i+1]-k)-h[i];
            } else {
                m+=h[i]-max(0,h[i+1]-k);
            }
        }
        if (m!=-1) printf("YES\n");
    }
    return 0;
}