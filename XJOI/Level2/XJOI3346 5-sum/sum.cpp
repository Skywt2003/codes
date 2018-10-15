#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=305;
int n;
long long a[6][maxn],s[2][maxn*maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline long long llread(){
    long long ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=(long long)-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=(long long)ret*10+(long long)(ch-'0'),ch=getchar();
    return ret*f;
}
inline bool check(long long x){
    if (x<s[1][1]||x>s[1][s[1][0]]) return false;
    int L=1,R=s[1][0];
    while (L<=R){
        int mid=((R-L)>>1)+L;
        if (s[1][mid]==x) return true; else
        if (s[1][mid]<x) L=mid+1; else R=mid-1;
    }
    return false;
}
int main(){
    n=read();
    for (int i=1;i<=5;i++)
    for (int j=1;j<=n;j++) a[i][j]=llread();

    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) s[0][++s[0][0]]=a[1][i]+a[2][j];
    sort(s[0]+1,s[0]+1+s[0][0]);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) s[1][++s[1][0]]=a[3][i]+a[4][j];
    sort(s[1]+1,s[1]+1+s[1][0]);

    for (int k=1;k<=n;k++){
        for (int i=1;i<=s[0][0];i++){
            if (check(-s[0][i]-a[5][k])) {printf("Yes\n");return 0;}
        }
    }
    printf("No\n");
    return 0;
}