#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
typedef long long li;
 
li min(li a, int b) {
  return min<li>(a, b);
}
 
const li inf = 1e18;
const int maxn = 300;
 
int n, a[maxn], goal;
li dp[maxn + 1][2];
 
li Solve(void) {
  dp[0][0] = 0;
  dp[0][1] = inf;
 
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i][1] = inf;
    if (a[i - 1] == goal) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][0];
    }
    li sum = 0, mn = inf;
    for (int j = i - 1; j >= 0; --j) {
      sum += a[j];
      mn = min(mn, a[j]);
      li val = (sum - mn) * mn + (i - j) * mn * goal;
      dp[i][0] = min(dp[i][0], dp[j][0] + val);
      dp[i][1] = min(dp[i][1], dp[j][1] + val);
    }
  }
 
  return dp[n][1];
}
 
li Main(void) {
  li ans = inf;
  for (int i = 0; i < n; ++i) {
    goal = a[i];
    ans = min(ans, Solve());
  }
  return ans;
}
 
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    li ans = Main();
    printf("%lld\n", ans);
  }
  return 0;
}
