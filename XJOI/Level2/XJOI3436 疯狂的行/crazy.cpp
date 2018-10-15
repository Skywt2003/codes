#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=44;
int n,ans=0,a[maxn];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        char s[maxn];
        scanf("%s",s+1);
        int j=n+1;while (s[j-1]=='0') j--,a[i]++;
    }
    int now=1;
    for (int i=n-1;i>=1;i--){
        int k=-1;
        for (int j=now;j<=n;j++) if (a[j]>=i){k=j;break;}
        for (int j=k;j>now;j--) swap(a[j],a[j-1]),ans++;
        now++;
    }
    printf("%d\n",ans);
    return 0;
}