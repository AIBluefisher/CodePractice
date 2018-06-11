#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXV 110
#define INF 110000000
int N,M;
int A,B,C;
int map[MAXV][MAXV];
int used[MAXV],dis[MAXV];

void fillMap()
{
  for(int i = 1; i < MAXV; i++)
  {
    for(int j = 1; j < MAXV; j++) map[i][j] = INF;
  }
}

void fillDist()
{
  for(int i = 1; i <= N; i++) dis[i] = map[1][i];
}

void dijkstra(int s)
{
  memset(used, 0, sizeof(used));
  fillDist();
  dis[s] = 0;

  while(true)
  {
    int v = -1;
    for(int u = 1; u <= N; u++)
    {
      if(!used[u] && (v == -1 || dis[u] < dis[v])) v = u;
    }
    if(v == -1) break;
    used[v] = true;

    for(int u = 1; u <= N; u++) dis[u] = min(dis[u], dis[v] + map[v][u]);
  }
  printf("%d\n",dis[N]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d%d",&N,&M) && (N != 0 && M != 0))
  {
    fillMap();
    while(M--)
    {
      scanf("%d%d%d",&A,&B,&C);
      map[A][B] = C;
      map[B][A] = C;
    }
    dijkstra(1);
  }
}
