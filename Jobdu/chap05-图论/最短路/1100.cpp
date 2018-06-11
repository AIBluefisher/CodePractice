#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 610
#define INF 0x0fffffff
int N,M;
int A,B,T;
int a[MAXN];
int map[MAXN][MAXN];
int used[MAXN];
int d[MAXN];

void init()
{
  for(int i = 0; i < MAXN; i++)
  {
    for(int j = 0; j < MAXN; j++)
    {
      map[i][j] = INF;
    }
  }
}

void dijkstra()
{
  for(int i = 1; i <= N; i++) d[i] = map[1][i];
  memset(used,0,sizeof(used));
  d[1] = 0;
  //int t = 0;
  //int pre = 1,cur = 1;
  while(true)
  {
    int v = -1;
    for(int u = 1; u <= N; u++)
    {
      if(!used[u] && (v == -1 || d[u] < d[v]))
      {
        v = u;
        //cur = a[v];
        //if(cur != pre) t++;
      }
    }

    if(v == -1) break;
    used[v] = 1;
    //pre = cur;
    for(int u = 1; u <= N; u++)
    {
      d[u] = min(d[u],d[v] + map[v][u]);
    }
  }
  printf("%d\n",d[2]);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d",&N) && (N != 0))
  {
    scanf("%d",&M);
    init();
    while(M--)
    {
      scanf("%d%d%d",&A,&B,&T);
      map[A][B] = map[B][A] = T;
    }
    for(int i = 1; i <= N; i++) scanf("%d",&a[i]);
    dijkstra();
  /*  for(int i = 1; i <= N; i++)
    {
      for(int j = 1; j <= N; j++)
      {
        printf("%d ",map[i][j]);
      }
      puts("");
    }*/
  }
}
