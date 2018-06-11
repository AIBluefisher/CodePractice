//百练 id=2386
#include <iostream>
using namespace std;

#define MAXN 110
int N,M;
char a[MAXN][MAXN];

void dfs(int x, int y)
{
  a[x][y] = '.';
  for(int i = -1; i <= 1; i++)
  {
    for(int j = -1; j <= 1; j++)
    {
      int ox = x + i;
      int oy = y + j;
      if(0 <= ox && ox < N && 0 <= oy && oy < M && a[ox][oy] == 'W') dfs(ox,oy);
    }
  }
  return;
}

int main()
{
  cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++) cin >> a[i][j];
  }
  int ans = 0;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      if(a[i][j] == 'W')
      {
        dfs(i,j);
        ans++;
      }
    }
  }
  cout << ans;
}
