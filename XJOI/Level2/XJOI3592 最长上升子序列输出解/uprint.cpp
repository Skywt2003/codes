#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream> //使用stringstream流应包含此头文件
using namespace std;
const int maxn=1005;
int n,a[maxn],f[maxn],pre[maxn],ans=0,cnt=0,tmp[maxn];
string prt[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++)
    for (int j=0;j<i;j++) if (a[j]<a[i]&&(f[j]+1>f[i]||(f[j]+1==f[i]&&a[j]<a[pre[i]]))){
        f[i]=f[j]+1;
        pre[i]=j;
    }
    for (int i=1;i<=n;i++) if (f[i]>ans) ans=f[i];
    stringstream ss;
    for (int i=1;i<=n;i++) if (f[i]==ans){
        cnt++;
        prt[cnt]="";
        int now=i;tmp[0]=0;
        while (now){
            tmp[++tmp[0]]=a[now];
            now=pre[now];
        }
        for (int j=tmp[0];j>=1;j--){
            ss.str("");ss<<tmp[j];
            prt[cnt]+=ss.str()+" ";
        }
    }
    sort(prt+1,prt+1+cnt);
    cout<<prt[1]<<endl;
    return 0;
}