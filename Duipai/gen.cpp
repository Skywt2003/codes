#include <bits/stdc++.h>
using namespace std;

const int maxn=200;
int n;
bool built[maxn];
vector<pair<int,int> > edges;
bool vis[maxn][maxn];

int main() {
    srand(time(NULL));
    n=rand()%100+5;
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
    int x=rand()%n+1;
    int y=rand()%n+1;
    while (x==y || vis[x][y] || vis[y][x]) x=rand()%n+1,y=rand()%n+1;
    edges.push_back(make_pair(x,y));
    for (int i=0;i<n;i++) printf("%d %d %d\n",edges[i].first,edges[i].second,rand()%13+1);
    return 0;
}
