#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 210
int n,m;
int k[MAXN],b[MAXN];
int dp[MAXN][MAXN];

void solve()
{
  int ps[MAXN],ds[MAXN];
  int k = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i > j) dp[i][j] = 0;
      else if( i == j) dp[i][j] = abs(k[i] - b[i]);
      else
      {
        //dp[i + 1][j + 1] = min(dp[i + 1][j],dp[i + 1][j] + abs(k[i] - b[i]));
        int temp = dp[i + 1][j] + abs(k[j + 1] - b[j + 1]);

        if(dp[i + 1][j] < temp)
        {
          dp[i + 1][j + 1] = temp;
          ps
        }
        if(dp[i + 1] == temp)
        {

        }
      }
    }
  }


}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d%d",&n,&m) && (n!=0 && m!=0))
  {
    for(int i = 0; i < n; i++) scanf("%d%d",k[i],b[i]);

    solve();
  }
}
