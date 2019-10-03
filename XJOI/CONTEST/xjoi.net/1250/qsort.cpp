#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

bool err=false;

const int N = 51;
int A[N], Random[N], id, n;
int qsort(int L, int R) {
    if (err) return 0;
	if (L >= R) return 0;
	int i = L, j = R;
	int x = Random[++id]; 
	int x0 = A[x];
	if (!(L <= x && x <= R)) {err=true;return 0;}
	while (i < j) {
		while (A[i] < A[x]) i++;
		while (A[j] > A[x]) j--;
		if (i <= j) {
			if (i == x) x = j;
			else if (j == x) x = i;
			swap(A[i], A[j]);
			i++; j--;
		}
	}
	swap(A[x], A[x0]);
	return R - L + qsort(L, x0 - 1) + qsort(x0 + 1, R);
}

int blt[N];
bool vis[N];
int ans=0,prt[N];

void DFS(int step){
    if (step==n+1){
        for (int i=1;i<=n;i++) A[i]=blt[i];
        id=0; int now=qsort(1,n);
        if (err==false && now>ans){
            ans=now;
            for (int i=1;i<=n;i++) prt[i]=blt[i];
        }
        return;
    }
    for (int i=1;i<=n;i++) if (!vis[i]){
        vis[i]=true;
        blt[step]=i;
        DFS(step+1);
        vis[i]=false;
    }
}

signed main(){
    n=read();
    if (n>=16){
        printf("No solution\n");
        return 0;
    }
    for (int i=1;i<=n;i++) Random[i]=read();

    DFS(1);

    if (ans==0) printf("No solution\n"); else {
        printf("Solution exists\n");
        printf("%lld\n",ans);
        for (int i=1;i<=n;i++) printf("%lld ",prt[i]);
        printf("\n");
    }
    return 0;
}