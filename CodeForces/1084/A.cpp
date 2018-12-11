#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=105;

int n,a[maxn],ans=1<<30;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

inline int myabs(int x){
    return x<0?-x:x;
}

int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int k=1;k<=n;k++){
        int now=0;
        for (int i=1;i<=n;i++){
            now+=a[i]*(myabs(i-k)+myabs(i-1)+myabs(k-1))*2;
        }
        ans=min(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}