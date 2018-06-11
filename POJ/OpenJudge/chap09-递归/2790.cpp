#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAXN 110
int k;
int n;
char a[MAXN][MAXN];
int xx1, yy1, xx2, yy2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x,int y)
{
  a[x][y] = '#';

  if(x == xx2 && y == yy2) return;

  for(int i = 0; i < 4; i++)
  {
    int ox = x + dx[i];
    int oy = y + dy[i];
    if(0 <= ox && ox < n && 0 <= oy && oy < n && a[ox][oy] == '.')
    {
      dfs(ox,oy);
    }
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&k);
  while(k--)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    if(a[xx1][yy1] == '#' || a[xx2][yy2] == '#')
    {
      puts("NO");
    }
    else
    {
      dfs(xx1,yy1);
      if(a[xx2][yy2] == '#') puts("YES");
      else puts("NO");
    }
    /*
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++) cout << a[i][j];
      puts("");
    }
    puts("");
    */
  }

}
