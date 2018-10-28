#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
using namespace std;
const int maxn=105;
int n=0,a[maxn];
bool f[maxn][maxn][8];
string ans[maxn][maxn][8];
inline string tostr(int x){
    stringstream ss;
    ss.str("");ss<<x;
    return ss.str();
}
int main(){
    char ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9'){
        a[++n]=ch-'0';
        ch=getchar();
    }
    if (a[n]==0){
        printf("YES\n0\n");
        return 0;
    }
    f[0][0][0]=1;
    for (int i=1;i<=n;i++)
    for (int j=0;j<=i;j++)
    for (int k=0;k<8;k++){
        if (f[i-1][j][k]) f[i][j][k]=1,ans[i][j][k]=ans[i-1][j][k]; else {
            if (j==0&&a[i]==0) continue;
            for (int t=0;t<8;t++) if ((2*t+a[i])%8==k){
                if (f[i-1][j-1][t]){
                    f[i][j][k]=1;
                    ans[i][j][k]=ans[i-1][j-1][t]+tostr(a[i]);
                }
            }
        }
    }
    for (int i=1;i<=n;i++) if (f[n][i][0]){
        printf("YES\n");
        cout<<ans[n][i][0]<<endl;
        return 0;
    }
    printf("NO\n");
    return 0;
}