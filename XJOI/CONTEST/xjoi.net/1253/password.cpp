#include <bits/stdc++.h>

using namespace std;
//#define int long long

map<string,bool> vis;
string a,b;
int len1,len2;

int ans=0;

signed main() {
    cin>>a>>b;
    len1=a.length(); len2=b.length();
    string st="";
    for (int i=0;i<len1;i++){
        st+=a[i]; string now=st;
        for (int j=0;j<len2;j++){
            now+=b[j];
            if (!vis[now]) vis[now]=true,ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
