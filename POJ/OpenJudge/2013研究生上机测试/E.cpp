//百练 id: 4103
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100
int n;
int used[MAXN][MAXN];
int dx[] = {-1, 0, 0}, dy[] = {0, -1, 1};
int ans = 0;

void dfs(int x,int y,int steps)
{
  used[x][y] = 1;
  if(steps == n)
  {
    ans++;
    return;
  }
  for(int i = 0; i < 3; i++)
  {
    int ox = x + dx[i];
    int oy = y + dy[i];
    if(!used[ox][oy])
    {
      dfs(ox,oy,steps + 1);
      used[ox][oy] = 0;
    }
  }
}

void solve()
{
  memset(used,0,sizeof(used));
  dfs(50,50,0);
  printf("%d",ans);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  scanf("%d",&n);
  solve();
}
