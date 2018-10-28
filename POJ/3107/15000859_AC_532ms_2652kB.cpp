#define maxm maxe
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=50005,maxe=2*maxn;
int n,lnk[maxn],nxt[maxe],son[maxe],tot=0,sum_sub[maxn],max_sub[maxn],ans_num=1<<30;
bool vis[maxn];
vector <int> ans;
inline void add(int x,int y){
    tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void DFS(int x){
    vis[x]=1;max_sub[x]=0;
    for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
        DFS(son[i]);
        sum_sub[x]+=sum_sub[son[i]];
        max_sub[x]=max(max_sub[x],max(max_sub[son[i]],sum_sub[son[i]]));
    }
    sum_sub[x]++;
    int ans_now=max(n-sum_sub[x],max_sub[x]);
    if(ans_now<ans_num){
        ans.clear();
        ans.push_back(x);
        ans_num=ans_now;
    } else if (ans_now==ans_num){
        ans.push_back(x);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    DFS(1);
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
