/**************************************************************
    Problem: 1042
    User: 陈煜
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1068 kb
****************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 110
char a[MAXN],b[MAXN];
int dp[MAXN][MAXN];

void solve()
{
  int len1 = strlen(a);
  int len2 = strlen(b);

  for(int i = 1; i <= len1; i++)
  {
    for(int j = 1; j <= len2; j++)
    {
      if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
    }
  }
  printf("%d\n",dp[len1][len2]);
}

int main()
{
  while(scanf("%s%s",a,b) != EOF)
  {
    memset(dp,0,sizeof(dp));
    solve();
  }
}
