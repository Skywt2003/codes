#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int tt=1e9+7;
int len;
string s;
vector<int> vec;

signed main(){
    cin>>s;
    len=s.length();
    vec.clear();
    for (int i=0;i<len;i++) if (s[i]=='a') vec.push_back(0); else if (s[i]=='b') vec.push_back(1);

    if ((int)vec.size()==0){
        cout<<0<<endl;
        return 0;
    }

    int ans=1;
    for (int i=0;i<(int)vec.size();) if (vec[i]==0 && (i==0 || vec[i-1]!=0)){
        int j=i;
        while (j+1<(int)vec.size() && vec[j+1]==0) j++;
        ans=ans*(j-i+2)%tt;
        i=j+1;
    } else i++;

    cout<<ans-1<<endl;
    return 0;
}