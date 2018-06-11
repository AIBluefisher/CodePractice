#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 30
#define INF 0x7fffffff
int n;
int map[MAXN][MAXN];
int used[MAXN];
char a,b;
int m,w;
int mincost[MAXN];

void init()
{
  for(int i = 0; i < MAXN; i++)
  {
    mincost[i] = INF;
    for(int j = 0; j < MAXN; j++)
    {
      map[i][j] = INF;
    }
  }
}

void prim()
{
  memset(used,0,sizeof(used));
  mincost[0] = 0;
  int res = 0;

  while(true)
  {
    int v = -1;
    for(int u = 0; u < n; u++)
    {
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if(v == -1) break;
    used[v] = 1;
    res += mincost[v];

    for(int u = 0; u < n; u++)
    {
      mincost[u] = min(mincost[u],map[v][u]);
    }
  }
  printf("%d\n",res);
}

int main()
{
  freopen("in.txt","r",stdin);

  while(cin >> n && n!= 0)
  {
    init();
    for(int i = 0; i < n - 1; i++)
    {
      cin >> a >> m;
      for(int j = 0; j < m; j++)
      {
        cin >> b >> w;
        int x = a - 'A';
        int y = b - 'A';
        map[x][y] = map[y][x] = w;
      }
    }
    prim();
  }
}
