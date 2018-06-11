#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 30
int W,H;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char piles[MAXN][MAXN];
int ans;

void dfs(int x,int y)
{
  for(int i = 0; i < 4; i++)
  {
    int ox = x + dx[i];
    int oy = y + dy[i];
    if((0 <= ox && ox < H) && (0 <= oy && oy < W) &&
        piles[ox][oy] == '.')
    {
      ans++;
      piles[ox][oy] = '@';
      dfs(ox, oy);
    }
  }
  return;
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  int nx,ny;
  while(cin >> W >> H && (W != 0 && H != 0))
  {
    ans = 1;
    for(int i = 0; i < H; i++)
    {
      for(int j = 0; j < W; j++)
      {
        cin >> piles[i][j];
        if(piles[i][j] == '@')
        {
          nx = i;
          ny = j;
        }
      }
    }

    dfs(nx,ny);
    cout << ans << endl;
  }
}
