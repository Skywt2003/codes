#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=200005;

int n,m,k=1,a[maxn],b[maxn];
priority_queue<int> heap1;
priority_queue<int,vector<int>,greater<int> > heap2;

signed main(){
    m=read();n=read();
    for (int i=1;i<=m;i++) a[i]=read();
    for (int i=1;i<=n;i++) b[i]=read();

    int j=0;
    for (int i=1;i<=m;i++){
        if (heap1.size() < j+1) heap1.push(a[i]); else heap2.push(a[i]);
        while (b[j+1]==i){
            j++;
            while (heap1.size() < j) heap1.push(heap2.top()),heap2.pop();
            while ((!heap1.empty())&&(!heap2.empty())&&heap1.top() > heap2.top()) heap1.push(heap2.top()),heap2.push(heap1.top()),heap1.pop(),heap2.pop();
            printf("%lld\n",heap1.top());
        }
    }
    // printf("All OK\n");
    return 0;
}