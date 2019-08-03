#include<bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=205,maxk=55,maxv=5005;

int k,v,n;
pair<int,int> a[maxn];

priority_queue<int> f[maxv];
priority_queue<int> tmp1,tmp2;

signed main(){
    k=read();v=read();n=read();
    for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();

    f[0].push(0);
    for (int i=1;i<=n;i++)
        for (int j=v;j>=a[i].first;j--){
            tmp1=f[j]; tmp2=f[j-a[i].first];
            while (!f[j].empty()) f[j].pop();
            for (int t=1;t<=k;t++){
                if (tmp1.empty() && tmp2.empty()) break;
                if (tmp2.empty()) f[j].push(tmp1.top()),tmp1.pop(); else
                if (tmp1.empty()) f[j].push(tmp2.top()+a[i].second),tmp2.pop(); else
                if (tmp1.top()>tmp2.top()+a[i].second) f[j].push(tmp1.top()),tmp1.pop(); else
                 f[j].push(tmp2.top()+a[i].second),tmp2.pop();
            }
        }

    int ans=0;
    for (int i=1;i<=k;i++) ans+=f[v].top(),f[v].pop();
    printf("%d\n",ans);
    return 0;
}