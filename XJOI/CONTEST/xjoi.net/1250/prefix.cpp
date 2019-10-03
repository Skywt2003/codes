#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2005,maxlen=205;
const int tt=1e9+7;

int n,m;

string s[maxn];
int len[maxn],slen=INF;

int f[2][maxn];
int v[26][maxlen];
int w[26];

signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) cin>>s[i];

    memset(w,0x3f,sizeof(w));
    sort(s+1,s+1+n);
    for (int i=1;i<=n;i++) len[i]=s[i].length(),slen=min(slen,len[i]),w[s[i][0]-'a']=min(w[s[i][0]-'a'],len[i]);
    for (int i=0;i<26;i++) if (w[i]==INF) w[i]=0;

    for (int i=1;i<=n;i++) if (s[i][0]==s[i-1][0]){
        bool flg=false;
        for (int j=1;j<w[s[i][0]-'a'];j++) if (s[i][j]!=s[i-1][j] || flg){
            flg=true; v[s[i][0]-'a'][j]++;
        }
    } else {
        for (int j=0;j<w[s[i][0]-'a'];j++) v[s[i][0]-'a'][j]=1;
    }

    // for (int i=0;i<26;i++){
    //     for (int j=0;j<w[i];j++) printf("%d ",v[i][j]);
    //     printf("\n");
    // }

    f[1][0]=1;
    for (int i=0;i<26;i++){
        memset(f[i&1],0,sizeof(f[i&1]));
        if (v[i][0]==0){
            for (int j=0;j<=m;j++) f[i&1][j]=f[1-(i&1)][j];
            continue;
        }
        for (int j=0;j<w[i];j++) if (v[i][j]){
            for (int k=m;k>=v[i][j];k--){
                f[i&1][k]=(f[i&1][k]+f[1-(i&1)][k-v[i][j]])%tt;
            }
        }
    }
    printf("%lld\n",f[25&1][m]);
    return 0;
}