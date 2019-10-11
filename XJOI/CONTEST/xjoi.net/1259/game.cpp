#include<bits/stdc++.h>
// #define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=205;

int n,len;
char a[maxn],b[maxn][maxn];
bool odd[maxn],even[maxn];
int num_both=0;

signed main(){
    scanf("%s",a+1); len=strlen(a+1);
    n=read();
    for (int i=1;i<=n;i++){
        int x=read(),y=read();
        for (int j=1;j<=y-x+1;j++) b[i][j]=a[j+x-1];
        if ((len-y)&1) odd[i]=true; else even[i]=true;
        for (int j=1;j<=n-(y-x);j++){
            bool flg=true;
            for (int k=j;k<=j+(y-x);k++) if (a[k]!=b[i][k-j+1]) {flg=false;break;}
            if (flg){
                if ((len-(j+(y-x)))&1) odd[i]=true; else even[i]=true;
            }
        }
    }

    int num_odd=0,num_even=0;
    for (int i=1;i<=n;i++){
        if (even[i]&&odd[i]) num_both++;
        num_odd+=odd[i]; num_even+=even[i];
        if (num_both&1) printf("Fir\nFir\n"); else
        if (num_odd&1) printf("Fir\nSec\n"); else printf("Sec\nFir\n");
    }
    return 0;
}