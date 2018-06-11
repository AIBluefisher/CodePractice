#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 0x7fffffff
#define MAXN 2010
int n,k;
int a[MAXN];
int dp[MAXN][MAXN];

void solve()
{
  memset(dp,0,sizeof(0));
  sort(a + 1,a + n + 1);
  for(int i = 1; i <= k; i++)
  {
    for(int j = 2 * i; j <= n; j++)
    {
      if(j > 2 * i) dp[i][j] = dp[i][j - 1];
      else dp[i][j] = INF;
      dp[i][j] = min(dp[i][j],dp[i - 1][j - 2] + (a[j] - a[j - 1]) * (a[j] - a[j - 1]) );
    }
  }
  printf("%d\n",dp[k][n]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d%d",&n,&k) !=EOF)
  {
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    solve();
  }

}
