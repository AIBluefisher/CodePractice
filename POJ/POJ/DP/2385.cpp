#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1010
int T,W;
int a[MAXN];
int dp[MAXN][MAXN];

void solve()
{
  for(int i = 1; i <= T; i++)
  {
    for(int j = 0; j <= W; j++)
    {
      if(j == 0) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
      if(j % 2 + 1 == a[i]) dp[i][j]++;
    }
  }
  printf("%d\n",dp[T][W]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d%d",&T,&W) != EOF)
  {
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= T; i++) scanf("%d",&a[i]);
    solve();
  }
}
