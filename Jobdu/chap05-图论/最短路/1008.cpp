#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXV 1010
#define INF 100000000

int n,m;
int a,b;
int dd,p;
int s,t;
int dist[MAXV][MAXV],price[MAXV][MAXV];
int d[MAXV],pr[MAXV],used[MAXV];

void init()
{
  for(int i = 1; i <= MAXV; i++)
  {
    for(int j = 1; j <= MAXV; j++)
    {
      dist[i][j] = INF;
      price[i][j] = INF;
    }
  }
}

void fill()
{
  for(int i = 1; i <= n; i++)
  {
    d[i] = dist[s][i];
    pr[i] = price[s][i];
  }
}

void dijkstra(int s)
{
  fill();
  memset(used,0,sizeof(used));
  d[s] = 0;
  pr[s] = 0;

  while(true)
  {
    int v = -1;
    for(int u = 1; u <= n; u++)
    {
      if(!(used[u]))
      {
        if(v == -1 || d[u] < d[v]) v = u;
        else if(d[u] == d[v] && price[u] < price[v]) v = u;
      }
    }

    if(v == -1) break;
    used[v] = true;

    for(int u = 1; u <= n; u++)
    {
      int td = d[v] + dist[v][u];
      if(d[u] > td)
      {
        d[u] = td;
        pr[u] = pr[v] + price[v][u];
      }
      else if(d[u] == td && pr[u] > pr[v] + price[v][u]) pr[u] = pr[v] + price[v][u];
    }
  }
  printf("%d %d\n",d[t],pr[t]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(scanf("%d%d",&n,&m) && (n != 0 && m != 0))
  {
    init();
    while(m--)
    {
      scanf("%d%d%d%d",&a,&b,&dd,&p);
      dist[a][b] = dist[b][a] = dd;
      price[a][b] = price[b][a] = p;
    }
    scanf("%d%d",&s,&t);
    dijkstra(s);
  }
}
