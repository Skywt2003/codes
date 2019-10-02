#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105;

int T,n,m;
int a[maxn][maxn];
int con[maxn][maxn][4];

char read_ch(){
    char ch=getchar();
    while (ch!='x'&&ch!='o') ch=getchar();
    return ch;
}

bool ok;

signed main(){
    T=read();
    while (T--){
        memset(con,0,sizeof(con));
        ok=false;
        n=read();m=read();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                a[i][j]=read_ch();
        
        for (int i=1;i<=n;i++){
            vector<int> vec; vec.clear();
            for (int j=1;j<=m;j++) if (a[i][j]=='o') vec.push_back(j);
            for (int j=1;j<(int)vec.size();j++) con[i][vec[j-1]][1]++,con[i][vec[j]][3]++;
        }
        for (int j=1;j<=m;j++){
            vector<int> vec; vec.clear();
            for (int i=1;i<=n;i++) if (a[i][j]=='o') vec.push_back(i);
            for (int i=1;i<(int)vec.size();i++) con[vec[i-1]][j][2]++,con[vec[i]][j][0]++;
        }
        int acnt=0;
        for (int i=1;i<=n && ok==false;i++)
            for (int j=1;j<=m && ok==false;j++){
                int now=0;
                for (int k=0;k<4;k++) now+=con[i][j][k];
                acnt+=now==1;
                if (now==2){
                    if ((con[i][j][0]&&con[i][j][2])||(con[i][j][1]&&con[i][j][3])){
                        acnt++;
                    }
                }
            }
        if (!ok) printf((acnt<=2)?"Possible\n":"Impossible\n");
    }
    return 0;
}