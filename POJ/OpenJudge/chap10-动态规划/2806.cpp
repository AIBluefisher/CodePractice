#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 210
char str1[MAXN],str2[MAXN];
int dp[MAXN][MAXN];

void solve()
{
  int len1 = strlen(str1),len2 = strlen(str2);

  for(int i = 0; i < len1; i++)
  {
    for(int j = 0; j < len2; j++)
    {
      if(str1[i] == str2[j])
      {
        dp[i+1][j+1] = dp[i][j] + 1;
      }
      else
      {
        dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
      }
    }
  }
/*
  for(int i = 0; i <= len1; i++)
  {
    for(int j = 0; j <= len2; j++)
    {
      printf("%d ",dp[i][j]);
    }
    puts("");
  }*/

  printf("%d\n",dp[len1][len2]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%s%s",str1,str2)!=EOF)
  {
    solve();
  }
}
