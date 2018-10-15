#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=100005;
int n,a[maxn],data[maxn];
map <int,int> mp;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=data[i]=read();
    sort(a+1,a+1+n);
    int cnt=0,i=1,j;
    while (i<=n){
        j=i;cnt++;mp[a[i]]=cnt;
        while (a[j+1]==a[i]&&j+1<=n) j++,cnt++;
        
        i=j+1;
    }
    for (int i=1;i<=n;i++) printf("%d ",mp[data[i]]);
    printf("\n");
    return 0;
}