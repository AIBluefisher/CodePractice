#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 110
int R,C;
int a[MAXN][MAXN];
int dx[] = {-1, 0, 0, 1},dy[] = {0, -1, 1, 0};
int used[MAXN][MAXN];
int dp[MAXN][MAXN];
//int ans;

int dfs(int x,int y)
{
  if(dp[x][y]) return dp[x][y];
  int ans = 1,temp;
  for(int i = 0; i < 4; i++)
  {
    int ox = x + dx[i];
    int oy = y + dy[i];
    if(0 <= ox && ox < R && 0 <= oy && oy < C && !used[ox][oy] && (a[ox][oy] < a[x][y]))
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
  int ans = 1;
  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++)
    {
      //memset(used,0,sizeof(0));
      ans = max(ans,dfs(i,j));
    }
  }
  printf("%d",ans);
}


int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d%d",&R,&C);
  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++) scanf("%d",&a[i][j]);
  }
  solve();
}
