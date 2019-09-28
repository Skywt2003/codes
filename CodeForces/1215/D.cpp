#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005;

int n;
int a[maxn];
int cnt1=0,cnt2=0;
int sum1=0,sum2=0;
int cnt,sum;

signed main(){
    n=read();
    char ch=getchar(); while ((ch<'0'||ch>'9')&&ch!='?') ch=getchar();
    for (int i=1;i<=n;i++){
        if (ch=='?'){
            if (i<=n/2) cnt1++; else cnt2++;
        } else {
            a[i]=ch-'0';
            if (i<=n/2) sum1+=a[i]; else sum2+=a[i];
        }
        if (i!=n) ch=getchar();
    }
    if (cnt1<cnt2) cnt=cnt2-cnt1,sum=sum1-sum2; else cnt=cnt1-cnt2,sum=sum2-sum1;
    if (9*cnt/2 != sum) printf("Monocarp\n"); else printf("Bicarp\n");
    return 0;
}