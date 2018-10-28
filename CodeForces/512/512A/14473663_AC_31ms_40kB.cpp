#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=105,maxm=30,maxe=1005;
int n,tot=0,f[maxm],lnk[maxm],son[maxe],nxt[maxe],len[maxn],ans_cnt=0,que[maxn];
bool aflg=true,vis[maxm];
char a[maxn][maxn],ans[maxm];
inline void add(int x,int y){tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;f[y]++;}
inline void Topology(){
    int head=0,tail=0;
    for (int i=1;i<=26;i++) if (f[i]==0){ans[++ans_cnt]=i+'a'-1;vis[i]=1;que[++tail]=i;}
    if (tail==0) {aflg=false;return;}
    while (head!=tail){
        head++;int xx=que[head];
        for (int i=lnk[xx];i;i=nxt[i]){
            f[son[i]]--;
            if (f[son[i]]<0){aflg=false;return;}
            if (!f[son[i]]){
                tail++;que[tail]=son[i];
                ans[++ans_cnt]=son[i]+'a'-1;
                vis[son[i]]=1;
            }
        }
    }
    for (int i=1;i<=26;i++) if (!vis[i]){
        if (f[i]){aflg=false;return;}
        ans[++ans_cnt]=i+'a'-1;
    }
    if (ans_cnt<26){aflg=false;return;}
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%s",a[i]+1),len[i]=strlen(a[i]+1);
    for (int i=1;i<n;i++){
        bool flg=false;
        for (int j=1;j<=min(len[i],len[i+1]);j++) if (a[i][j]-a[i+1][j]){
            add(a[i][j]-'a'+1,a[i+1][j]-'a'+1);
            flg=true;break;
        }
        if ((!flg)&&(len[i]>len[i+1])){printf("Impossible\n");return 0;}
    }
    Topology();
    if (aflg==false){printf("Impossible\n");return 0;}
    ans[ans_cnt+1]=0;
    printf("%s\n",ans+1);
    return 0;
}