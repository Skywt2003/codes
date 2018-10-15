#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1005;
int n,x,y,fa[maxn];
vector<int> que1,que2;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    n=read();
    for (int i=2;i<=n;i++){
        int now=read();
        fa[i]=now;
    }
    x=read();y=read();
    while (x) que1.push_back(x),x=fa[x];
    while (y) que2.push_back(y),y=fa[y];
    reverse(que1.begin(),que1.end());
    reverse(que2.begin(),que2.end());
    int x=0;
    while (que1[x]==que2[x]) x++;
    x--;
    printf("%d\n",que1[x]);
    return 0;
}