#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n;

priority_queue<int,vector<int>,greater<int> > heap;

signed main(){
    n=read();
    while (n--){
        int opt=read();
        if (opt==1){
            int x=read();
            heap.push(x);
        } else if (opt==2){
            printf("%lld\n",heap.top());
        } else if (opt==3){
            heap.pop();
        }
    }
    return 0;
}

