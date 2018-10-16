#include <bits/stdc++.h>
using namespace std;

const int maxn=20;
int n;
bool built[maxn];
vector<pair<int,int> > edges;
bool vis[maxn][maxn];

int main() {
    srand(time(NULL));
    n=rand()%10+5;
    printf("%d\n",n);
    edges.clear();
    built[1]=true;
    for (int i=2;i<=n;i++){
        int now=rand()%(i-1)+1;
        while (!built[now]) now=rand()%(i-1)+1;
        edges.push_back(make_pair(now,i));
        vis[now][i]=vis[i][now]=true;
        built[i]=true;
    }
    for (int i=0;i<n-1;i++) printf("%d %d %d\n",edges[i].first,edges[i].second,rand()%6+1);
    return 0;
}
