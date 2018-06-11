#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 30
int k;
int a[MAXN];
int dp[MAXN];

void solve()
{
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  for(int i = 1; i < k; i++)
  {
    int temp = 0;
    for(int j = 0; j < i; j++)
    {
      if(a[i] <= a[j]) temp = max(temp,dp[j]);
    }
    dp[i] = temp + 1;
  }
  int ans = 0;
  for(int i = 0; i < k; i++) ans = max(ans,dp[i]);
  //for(int i = 0; i < k; i++) printf("%d ",dp[i]);
  printf("%d\n",ans);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d",&k) != EOF)
  {
    for(int i = 0; i < k; i++) scanf("%d",&a[i]);
    solve();
  }
}
