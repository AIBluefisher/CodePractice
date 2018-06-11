#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 110
int n;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

void solve()
{

}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      scanf("%d",&a[i][j]);
    }
  }

  solve();
}
