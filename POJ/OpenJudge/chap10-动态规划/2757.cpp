#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAXN 1010
int a[MAXN];
int n;
int dp[MAXN];

void solve()
{
  for(int i = 0; i < n; i++) dp[i] = 1;

  for(int i = 1; i < n; i++)
  {
    int temp = 0;
    for(int j = 0; j < i; j++)
    {
      if(a[i] > a[j])
      {
        if(temp < dp[j]) temp = dp[j];
      }
    }
    dp[i] = temp + 1;
  }

  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    ans = max(ans,dp[i]); //printf("%d ",dp[i]);
  }
  //puts("");
  printf("%d",ans);
}

int  main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);

  for(int i = 0; i < n; i++) scanf("%d",&a[i]);

  solve();
}
