#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 360

int N;
int bowling[MAXN][MAXN];
int dp[MAXN][MAXN];

void solve()
{
  //dp[0][0] = bowling[0][0];

  for(int i=1;i<N+1;i++)
  {
    for(int j=1;j<i+1;j++)
    {
      dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]) + bowling[i-1][j-1];
    }
  }
  int ans=0;
  for(int i=1;i<N+1;i++)
  {
    ans=max(ans,dp[N][i]);
  }
  printf("%d",ans);
  //printf("%d\n",bowling[1][1]);
}

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<i+1;j++)
    {
      scanf("%d",&bowling[i][j]);
    }
  }
  solve();
/*
  for(int i=1;i<N+1;i++)
  {
    for(int j=1;j<i+1;j++)
    {
      printf("%d ",dp[i][j]);
    }
    puts("");
  }*/
}
