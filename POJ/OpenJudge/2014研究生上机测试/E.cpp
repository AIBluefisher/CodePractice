//百练 id:1088
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 110
int R,C;
int a[MAXN][MAXN];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int dp[MAXN][MAXN];

int dfs(int x, int y)
{
  if(dp[x][y]) return dp[x][y];
  int ans = 1;
  int temp = 0;
  for(int k = 0; k < 4; k++)
  {
    int ox = x + dx[k];
    int oy = y + dy[k];
    if(0 <= ox && ox < R && 0 <= oy && oy < C && a[x][y] > a[ox][oy])
    {
      temp = dfs(ox,oy) + 1;
      ans = max(ans,temp);
    }
  }
  return dp[x][y] = ans;
}

void solve()
{
  memset(dp,0,sizeof(dp));
  int ans = 0;
  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++)
    {
      dp[i][j] = dfs(i,j);
      ans = max(ans,dp[i][j]);
    }
  }
  printf("%d",ans);
}

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

  scanf("%d%d",&R,&C);
  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++) scanf("%d",&a[i][j]);
  }
  solve();
}
