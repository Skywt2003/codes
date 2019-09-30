#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f;

const int maxn=105;

int n=0;
int a[maxn];
int cnt1=0;

signed main(){
    char ch=getchar(); while (ch!='0' && ch!='1') ch=getchar();
    while (ch=='0'||ch=='1'){
        a[++n]=ch-'0';
        if (ch=='1') cnt1++;
        ch=getchar();
    }
    if (cnt1==0) printf("0\n"); else
    if (cnt1==1 && (n&1)) printf("%d\n",(n+1)/2-1); else 
    printf("%d\n",(n+1)/2);
    return 0;
}