#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

int T;
int n,k,a[maxn],sum;

int L,R;

#define mid (((R-L)>>1)+L)

bool check1(int x){
    int tot=0;
    for (int i=1;i<=n;i++) if (x>a[i]) tot+=x-a[i];
    // printf("Check1 %lld = %d\n",x,tot<=k);
    return tot<=k;
}

bool check2(int x){
    int tot=0;
    for (int i=1;i<=n;i++) if (a[i]>x) tot+=a[i]-x;
    // printf("Check2 %lld = %d\n",x,tot<=k);
    return tot<=k;
}

signed main(){
    T=read();
    while (T--){
        sum=0;

        n=read();k=read();
        for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
        // sort(a+1,a+1+n);
        
        int num1=-1,num2=-1;
        L=0,R=1e9;
        while (L<=R){
            if (check1(mid)) num1=mid,L=mid+1; else R=mid-1;
        }
        L=0,R=1e9;
        while (L<=R){
            if (check2(mid)) num2=mid,R=mid-1; else L=mid+1;
        }
        // printf("%lld %lld\n",num1,num2);

        if (num1>=num2) printf("%d\n",sum%n!=0); else printf("%lld\n",num2-num1);
    }
    return 0;
}