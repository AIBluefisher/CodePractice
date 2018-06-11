#include <cstdio>

#define MAXN 1000001
int N;
int dp[MAXN];

void solve()
{
  dp[1] = 1;
  for(int i = 2; i <= N; i++)
  {
    if(i & 1) dp[i] = dp[i - 1];
    else dp[i] = ( dp[i - 1] + dp[i >> 1] ) % 1000000000;
  }
  printf("%d",dp[N]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&N);
  solve();
}
