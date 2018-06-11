/**************************************************************
    Problem: 1017
    User: 陈煜
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:1060 kb
****************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100
#define INF 100000000
int N;
int map[MAXN][MAXN];
int x,y,dis;
int minCost[MAXN];
int used[MAXN];

void init()
{
  for(int i = 1; i <= MAXN; i++)
  {
    minCost[i] = INF;
    for(int j = 0; j <= MAXN; j++) map[i][j] = INF;
  }
}

void prim()
{
  int ans = 0;
  minCost[1] = 0;
  memset(used,0,sizeof(used));

  while(true)
  {
    int v = -1;
    for(int u = 1; u <= N; u++)
    {
      if(!used[u] && (v == -1 || minCost[v] > minCost[u])) v = u;
    }

    if(v == -1) break;
    used[v] = 1;
    ans += minCost[v];
    for(int u = 1; u <= MAXN; u++) minCost[u] = min(minCost[u], map[v][u]);
  }
  printf("%d\n",ans);
}

int main()
{
  int m;
  while(scanf("%d",&N) && (N != 0))
  {
    init();
    m = N * (N - 1) / 2;
    for(int i = 0; i < m; i++)
    {
      scanf("%d%d%d",&x,&y,&dis);
      map[x][y] = map[y][x] = dis;
    }
    prim();
  }

}
