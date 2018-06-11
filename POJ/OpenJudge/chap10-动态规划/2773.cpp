#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 110
int T,M;
int t[MAXN],v[MAXN];
int dp[MAXN][MAXN];

void solve()
{
  memset(dp,0,sizeof(dp));
  for(int i = M - 1; i >= 0; i--)
  {
    for(int j = 0; j <= T; j++)
    {
      if(j < t[i]) dp[i][j] = dp[i + 1][j];
      else dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - t[i]] + v[i]);
    }
  }
  printf("%d",dp[0][T]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d%d",&T,&M);
  for(int i = 0; i < M; i++) scanf("%d%d",&t[i],&v[i]);
  solve();
}
