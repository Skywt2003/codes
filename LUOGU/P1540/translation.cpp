#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

int n,m;
int head=1,tail=0;
int que[maxn];
int ans=0;

signed main(){
    m=read(); n=read();
    while (n--){
        int x=read();
        bool flg=false;
        for (int i=head;i<=tail;i++) if (que[i]==x) {flg=true;break;}
        if (!flg){
            ans++; que[++tail]=x;
            if (tail-head+1 > m) head++;
        }
    }
    printf("%d\n",ans);
    return 0;
}