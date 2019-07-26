#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int n;
vector<int> vec;

void make_answer(int x){
    if (x==0) return;
    vec.push_back(x-x/2);
    make_answer(x/2);
}

signed main(){
    n=read();
    
    make_answer(n);
    
    sort(vec.begin(),vec.end());
    printf("%d\n",(int)vec.size());
    for (int i=0;i<vec.size();i++) printf("%d ",vec[i]); printf("\n");
    return 0;
}
