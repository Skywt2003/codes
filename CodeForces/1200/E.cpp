#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=10005,maxlen=1e6+5,LEN=1e6;
const int tt=1e9+7;
const int hv[2]={1926,817};

int n;
char s[maxlen],ans[maxlen];
int len=0;

int qsm[2][maxlen];

signed main(){
    n=read();
    qsm[0][0]=qsm[1][0]=1;
    for (int i=1;i<=LEN;i++) qsm[0][i]=qsm[0][i-1]*hv[0]%tt,qsm[1][i]=qsm[1][i-1]*hv[1]%tt;

    while (n--){
        scanf("%s",s+1); int nowlen=strlen(s+1);
        int hash1[2],hash2[2],now=0;
        hash1[0]=hash1[1]=hash2[0]=hash2[1]=0;
        for (int i=1;i<=min(nowlen,len);i++){
            for (int k=0;k<2;k++){
                hash1[k]=(hash1[k]*hv[k]+s[i])%tt;
                hash2[k]=(hash2[k]+ans[len-i+1]*qsm[k][i-1])%tt;
            }
            if (hash1[0]==hash2[0] && hash1[1]==hash2[1]) now=i;
        }
        for (int i=now+1;i<=nowlen;i++) ans[++len]=s[i];
    }
    for (int i=1;i<=len;i++) putchar(ans[i]);
    printf("\n");
    return 0;
}