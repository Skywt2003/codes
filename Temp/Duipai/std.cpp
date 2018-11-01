// POJ 3715
#include <cstdio>
#include <cstring>
#include <vector>
const int MAXN = 205;

int N, M, T, col[MAXN];

namespace FastIO {
	template <typename T>
	void read(T & x) {
		x = 0; register char ch = getchar();
		for (; ch < '0' || ch > '9'; ch = getchar());
		for (; ch >= '0' && ch <= '9'; x = (x << 3) + (x << 1) + (ch ^ '0'), ch = getchar());
	}
} // FastIO
namespace Graph {
	std::vector<int> V[2], G[MAXN];
	int flag[MAXN];

	inline void init() {
		V[0].clear(), V[1].clear();
		for (int i = 0; i < N; i++) G[i].clear();
		memset(flag, 0, sizeof flag);
	}
	inline void ins_v(int col, int u) {
		V[col].push_back(u);
	}
	void add_edge(int u, int v) {
		if (col[u] == col[v]) return;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	inline void remark(int u) {
		flag[u] ^= 1;
	}
	int matching();
	int matching(int mrku);
} // Graph

void solve();

int main() {
	FastIO::read(T);
	while (T--) solve();
	return 0;
}

void solve() {
	using FastIO::read;
	read(N), read(M);
	Graph::init();
	for (int i = 0; i < N; i++) {
		read(col[i]);
		Graph::ins_v(col[i], i);
	}
	for (int i = 0, x, y; i < M; i++) {
		read(x), read(y);
		Graph::add_edge(x, y);
	}
	int T = Graph::matching();
	printf("%d ", T);
	for (int i = 0; i < N; i++)
		if (Graph::matching(i) < T) {
			--T;
			printf("%d ", i);
		}
		else Graph::remark(i);
	putchar('\n');
}

namespace Graph {
	bool vis[MAXN];
	int match[MAXN];

	bool dfs(int u) {
		// for (auto v : G[u])
		for (std::vector<int>::iterator v = G[u].begin(); v != G[u].end(); ++v)
			if (!vis[*v] && !flag[*v]) {
				vis[*v] = true;
				if (match[*v] == -1 || dfs(match[*v])) {
					match[*v] = u;
					return true;
				}
			}
		return false;
	}
	int matching() {
		memset(match, 0xff, sizeof match);
		int res = 0;
		// for (auto i : V[0])
		for (std::vector<int>::iterator i = V[0].begin(); i != V[0].end(); ++i) {
			memset(vis, 0, sizeof vis);
			if (dfs(*i)) ++res;
		}
		return res;
	}
	int matching(int mrku) {
		memset(match, 0xff, sizeof match);
		remark(mrku);
		int res = 0;
		// for (auto i : V[col[mrku] ^ 1]) 
		for (std::vector<int>::iterator i = V[col[mrku] ^ 1].begin(); i != V[col[mrku] ^ 1].end(); ++i) {
			if (flag[*i]) continue;
			memset(vis, 0, sizeof vis);
			if (dfs(*i)) ++res;
		}
		return res;
	}
} // Graph
