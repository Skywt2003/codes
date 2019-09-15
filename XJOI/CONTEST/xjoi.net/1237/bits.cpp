#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

char read_ch(){
    char ch=getchar();
    while (ch!='X' && ch!='A' && ch!='O') ch=getchar();
    return ch;
}

const int maxm=35,maxn=1e5+5;

int n,m,c;
int a[maxn],fin[maxm];
int num[maxn][maxm];
char opt[maxn];
int puted[maxm];

bool allor=true,alland=true;

int pop_count(int x){
    int ret=0;
    while (x) ret+=x&1,x>>=1;
    return ret;
}

bool DFS(int x){
    if (x==n){
        int now=puted[1];
        for (int i=2;i<=n;i++){
            if (opt[i-1]=='A') now=now&puted[i]; else
            if (opt[i-1]=='O') now=now|puted[i]; else
            if (opt[i-1]=='X') now=now^puted[i];
        }
        return now==c;
    }
    for (int i=0;i<1<<m;i++) if (pop_count(i)==a[x+1]){
        puted[x+1]=i;
        if (DFS(x+1)) return true;
    }
    return false;
}

signed main(){
    n=read();m=read();c=read();

    for (int i=1;i<n;i++){
        char ch=read_ch();
        if (ch=='X') read_ch();
        if (ch!='O') allor=false;
        if (ch!='A') alland=false;
        opt[i]=ch;
    }
    for (int i=1;i<=n;i++) a[i]=read();

    if (allor){
        while (c) fin[++fin[0]]=c&1,c>>=1;
        for (int i=1;i<=m;i++) if (fin[i]){
            bool flg=false;
            for (int j=1;j<=n;j++) if (a[j]){
                a[j]--,num[j][i]=1,flg=true;
                break;
            }
            if (!flg){printf("OvO\n");return 0;}
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m && a[i]>=1;j++) if (num[i][j]==0 && fin[j]==1)
                a[i]--,num[i][j]=1;
            if (a[i]){printf("OvO\n");printf("a[%d]=%d\n",i,a[i]);return 0;}
        }
        for (int i=1;i<=n;i++){
            int now=0;
            for (int j=1;j<=m;j++) now=(now<<1)+num[i][j];
            printf("%d ",now);
        }
        printf("\n");
        return 0;
    }
    if (alland){
        while (c) fin[++fin[0]]=c&1,c>>=1;
        for (int i=1;i<=m;i++) if (fin[i]){
            for (int j=1;j<=n;j++) if (a[j]){
                a[j]--,num[j][i]=1;
            } else {printf("OvO\n");return 0;}
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m && a[i]>=1;j++) if (num[i][j]==0 && fin[j]==0 && puted[j]+1!=n)
                a[i]--,num[i][j]=1,puted[j]++;
            if (a[i]){printf("OvO\n");return 0;}
        }
        for (int i=1;i<=n;i++){
            int now=0;
            for (int j=m;j>=1;j--) now=(now<<1)+num[i][j];
            printf("%d ",now);
        }
        printf("\n");
        return 0;
    }
    if (DFS(0)==false) printf("OvO\n"); else {
        for (int i=1;i<=n;i++) printf("%d ",puted[i]);
        printf("\n");
    }
    return 0;
}