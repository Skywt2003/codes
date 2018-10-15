#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const int maxn=10005;
map <string,int> value;
map <string,bool> vis;
int n,m,nn=0,cnt[maxn];
__int128 ans=0;
string s,a[maxn];
inline void write(__int128 x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main(){
    scanf("%d%d",&n,&m);
    int x;
    for (int i=1;i<=n;i++){
        cin>>s>>x;
        if (x==0) continue;
        a[++nn]=s;cnt[nn]=x;
    }
    for (int i=1;i<=m;i++){
        cin>>s>>x;
        vis[s]=1;value[s]=x;
    }
    for (int i=1;i<=nn;i++){
        if (!vis[a[i]]){printf("Unknow\n");return 0;}
        ans=ans+(__int128)cnt[i]*value[a[i]];
    }
    write(ans);
    return 0;
}