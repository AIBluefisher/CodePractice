/**************************************************************
    Problem: 1144
    User: 陈煜
    Language: C++
    Result: Accepted
    Time:10 ms
    Memory:1148 kb
****************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct
{
  float x;
  float y;
}location;

#define MAXN 110
#define MAXE 10010
#define INF 100000000
int n;
float map[MAXN][MAXN];
location loc[MAXE];
float mincost[MAXN];
int used[MAXN];

void init()
{
  for(int i = 1; i <= MAXN; i++)
  {
    mincost[i] = INF;
    for(int j = 1; j <= MAXN; j++) map[i][j] = INF;
  }
}

void computeDist()
{
  float xtemp,ytemp;
  for(int i = 1; i <= n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
      xtemp = (loc[i].x - loc[j].x) * (loc[i].x - loc[j].x);
      ytemp = (loc[i].y - loc[j].y) * (loc[i].y - loc[j].y);
      map[i][j] = map[j][i] = sqrt(xtemp + ytemp);
    }
  }
}

void prim()
{
  computeDist();
  memset(used,0,sizeof(used));
  mincost[1] = 0;
  float ans = 0;
  while(true)
  {
    int v = -1;
    for(int u = 1; u <= n; u++)
    {
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if(v == -1) break;
    used[v] = 1;
    ans += mincost[v];
    for(int u = 1; u <= n; u++) mincost[u] = min(mincost[u],map[v][u]);
  }
  printf("%.2f\n",ans);
}

int main()
{
  while(scanf("%d",&n) != EOF)
  {
    init();
    for(int i = 1; i <= n; i++) scanf("%f%f",&loc[i].x,&loc[i].y);
    prim();
  }
}
