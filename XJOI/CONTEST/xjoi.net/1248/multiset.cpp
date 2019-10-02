#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=100005;

int n,k,cnt=0;
int a[maxn];
multiset<int> s[maxn];
multiset<int>::iterator it;
int tmp1[maxn],tmp2[maxn];

bool compare_set(multiset<int> aa,multiset<int> bb){
    tmp1[0]=tmp2[0]=0;
    for (it=aa.begin();it!=aa.end();it++) tmp1[++tmp1[0]]=(*it);
    for (it=bb.begin();it!=bb.end();it++) tmp2[++tmp2[0]]=(*it);
    for (int i=1;i<=min(tmp1[0],tmp2[0]);i++) if (tmp1[i]!=tmp2[i]){
        if (i-1>=1 && tmp1[i]==tmp1[i-1]) return true; else
        if (i-1>=1 && tmp2[i]==tmp1[i-1]) return false; else
        return tmp1[i]<tmp2[i];
    }
    return tmp1[0]>tmp2[0];
}

signed main(){
    n=read(); k=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++){
        multiset<int> now; now.clear();
        for (int j=i;j<=n;j++){
            now.insert(a[j]);
            s[++cnt]=now;
        }
    }
    sort(s+1,s+1+cnt,compare_set);
    for (it=s[k].begin();it!=s[k].end();it++) printf("%d ",(*it));
    printf("\n");
    return 0;
}