#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,maxlen=105;
int n=0,len,lnk[maxn],son[maxn*maxlen],nxt[maxn*maxlen],f[maxn],que[maxn],tot=0;
char a[maxlen];
inline void add(int x,int y){
    if (x>n) n=x;
    if (y>n) n=y;
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;f[y]++;
}
inline bool Topology(){
    int head=0,tail=0;
    for (int i=1;i<=n;i++) if (f[i]==0) que[++tail]=i;
    while (head!=tail){
        head++;
        for (int i=lnk[que[head]];i;i=nxt[i]){
            f[son[i]]--;
            if (f[son[i]]<0) return false;
            if (f[son[i]]==0){
                tail++;
                que[tail]=son[i];
            }
        }
    }
    for (int i=1;i<=n;i++) if (f[i]) return false;
    return true;
}
int main(){
    while (scanf("%s",a+1)!=-1){
        len=strlen(a+1);
        for (int i=1;i<len;i++) if (a[i]!=a[i+1]) add(a[i]-'a'+1,a[i+1]-'a'+1);
    }
    if (Topology()) printf("Possible\n"); else printf("Impossible\n");
    return 0;
}