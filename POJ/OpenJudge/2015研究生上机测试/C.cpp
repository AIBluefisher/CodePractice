#include <cstdio>
#include <cstring>

#define MAXN 110
int r,c;
int a[MAXN][MAXN];
int used[MAXN][MAXN];
int turn;
int count;

void dfs(int x,int y)
{
  if(count == r * c) return;
  count++;
  printf("%d\n",a[x][y]);
  used[x][y] = 1;

  if(turn == 1 && (y + 1 == c || used[x][y + 1])) turn = 2;
  if(turn == 2 && (x + 1 == r || used[x + 1][y])) turn = 3;
  if(turn == 3 && (y - 1 < 0 || used[x][y - 1])) turn = 4;
  if(turn == 4 && (x - 1 < 0 || used[x - 1][y])) turn = 1;

  if(!used[x][y + 1] && turn == 1) dfs(x,y + 1);
  if(!used[x + 1][y] && turn == 2) dfs(x + 1,y);
  if(!used[x][y - 1] && turn == 3) dfs(x,y - 1);
  if(!used[x - 1][y] && turn == 4) dfs(x - 1,y);
}

void solve()
{
  memset(used,0,sizeof(used));
  turn = 1;
  count = 0;
  dfs(0,0);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d%d",&r,&c);
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++) scanf("%d",&a[i][j]);
  }
  solve();
}
