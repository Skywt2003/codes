// 181019

#include<bits/stdc++.h>

const int maxn=1005,maxe=10005;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int dst[maxn];

namespace Dijkstra{
	priority_queue<pair<int,int> > heap;
	
}