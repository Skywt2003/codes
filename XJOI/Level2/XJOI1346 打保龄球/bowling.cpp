#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=20;
int n=0,a[maxn][2],rst[maxn];
bool flg=true,vis[maxn];
int main(){
    char ch=getchar();while (ch!='/'&&(ch<'0'||ch>'9')) ch=getchar();
    while (1){
        if (ch=='/') a[++n][0]=10; else a[++n][0]=ch-'0';
        ch=getchar();while (ch!='/'&&(ch<'0'||ch>'9')) {if (ch==10||ch==13||ch==-1) {flg=false;break;} ch=getchar();}
        if (!flg) break;
        if (a[n][0]==10) continue;
        if (ch=='/') a[n][1]=10-a[n][0]; else a[n][1]=ch-'0';
        ch=getchar();while (ch!='/'&&(ch<'0'||ch>'9')) {if (ch==10||ch==13||ch==-1) {flg=false;break;} ch=getchar();}
        if (!flg) break;
    }
    // printf("N=%d\n",n);
    for (int i=1;i<=n;i++){
        if (a[i][0]==10){
            if (i+1>n) {vis[i]=1;continue;}
            rst[i]=10+a[i+1][0];
            if (a[i+1][0]==10){
                if (i+2>n) {vis[i]=1;continue;}
                rst[i]+=a[i+2][0];
            }else rst[i]+=a[i+1][1];
        } else if (a[i][0]+a[i][1]==10){
            if (i+1>n) {vis[i]=1;continue;}
            rst[i]=10+a[i+1][0];
        }
        else rst[i]=a[i][0]+a[i][1];
    }
    for (int i=1;i<=min(n-1,10);i++) if (!vis[i]) printf("%d ",rst[i]);printf("\n");
    for (int i=1;i<=min(n-1,10);i++) if (!vis[i]) rst[i]=rst[i-1]+rst[i]; else rst[i]=rst[i-1];
    for (int i=1;i<=min(n-1,10);i++) if (!vis[i]) printf("%d ",rst[i]);printf("\n");
    return 0;
}