/*
 * XJOI CONTEST 1014
 * T1 - 平衡串
 * 181006 By SkyWT
 */
 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
 
using namespace std;
 
#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))
 
#define int long long
 
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
 
const int maxn=105;
int n,need=0;
string a[maxn];
int cnt[256];
 
signed main(){
    n=read();
    if (n<=26){
        for (int i=0;i<n;i++) putchar(i+'a'),printf("\n");
        return 0;
    }
    for (int i=1;i<=n;i++) a[i]="";
    for (int i=4;i<=n;i++){
        char now=(((i-4)%20)+'g');
        // printf("NOW:");putchar(now);printf("\n");
        a[i]+=now;
        need+=cnt[now];
        cnt[now]++;
    }
    // printf("OK HERE\n");
    a[1]="a";a[2]="c";a[3]="e";
    for (int i=1;i<=99 && need>0;i++) a[1]+=(i&1)?("b"):("a"),need--;
    for (int i=1;i<=99 && need>0;i++) a[2]+=(i&1)?("d"):("c"),need--;
    for (int i=1;i<=99 && need>0;i++) a[3]+=(i&1)?("f"):("e"),need--;
    if (need>0) printf("ERROR: need still >0\n");
    for (int i=1;i<=n;i++) cout<<a[i]<<endl;
    return 0;
}