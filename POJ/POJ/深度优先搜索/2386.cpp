#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 110
int N,M;
char a[MAXN][MAXN];

void DFS(int x, int y)
{
  a[x][y] = '.';
  for(int i = -1; i <= 1; i++)
  {
    for(int j = -1; j <=1; j++)
    {
      int ox = x + i;
      int oy = y + j;
      if(0 <= ox && ox < N && 0 <= oy && oy < M && a[ox][oy] == 'W') DFS(ox, oy);
    }
  }
  return;
}

void solve()
{
  int count = 0;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      if(a[i][j] == 'W')
      {
        DFS(i,j);
        count++;
      }
    }
  }
  cout << count;
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++) cin >> a[i][j];
  }
  solve();
}
