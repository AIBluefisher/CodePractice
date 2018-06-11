#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXV 30
#define MAXE 80
#define INF 100000000
int n,m,w;
char s,t;
int map[MAXV][MAXV];
int used[MAXV];
int mincost[MAXV];

void init()
{
  for(int i = 0; i < MAXV; i++)
  { mincost[i] = INF;
    for(int j = 0; j < MAXV; j++) map[i][j] = INF;
  }
}

void prim()
{
  memset(used,0,sizeof(used));
  int ans = 0;
  mincost[0] = 0;

  while(true)
  {
    int v = -1;
    for(int u = 0; u < n; u++)
    {
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if(v == -1) break;
    used[v] = 1;
    ans += mincost[v];
    for(int u = 0; u < n; u++)
    {
      mincost[u] = min(mincost[u],map[v][u]);
    }
  }
  cout << ans;
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  cin >> n;
  init();
  for(int i = 0; i < n - 1; i++)
  {
    cin >> s >> m;
    for(int j = 0; j < m; j++)
    {
      cin >> t >> w;
      map[s - 'A'][t - 'A'] = map[t - 'A'][s - 'A'] = w;
    }
  }
  prim();
}
