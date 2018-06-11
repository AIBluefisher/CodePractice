#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

//01背包
/******************************************************************
void bag_solve()
{
  for(int i = n - 1; i >= 0; i--)
  {
    for(int j = 0; j <= W; j++)
    {
      if(j < w[i]) dp[i][j] = dp[i + 1][j];
      else dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - w[i]] + v[i]);
    }
  }
  printf("%d\n",dp[0][W]);
}
***********************************************************************/

//全排列
/********************************************
void solve()
{
  len = strlen(str);
  sort(str,str + len);
  puts(str);
  while(next_permutation(str,str + len))
  {
    puts(str);
  }
}
***********************************************/

/*********************并查集*****************************
typedef struct
{
  int parent;
  int rank;
}UFSTree;

void init()
{
  for(int i = 0; i < n; i++)
  {
    t[i].parent = i;
    t[i].rank = 0;
  }
}

int findRoot(int x)
{
  if(t[x].parent == x) return x;
  return findRoot(t[x].parent);
}

void uni(int x,int y)
{
  int xx = findRoot(x);
  int yy = findRoot(y);

  if(t[xx].rank > t[yy].rank) t[yy].parent = xx;
  else
  {
    t[xx].parent = yy;
    if(t[xx].rank == t[yy].rank) t[yy].rank++;
  }
}
************************************************************/
//bellman-ford
/*****************************************************************
struct edge {int from,to,cost};
edge es[MAX_E];

int d[MAX_V];
int V,E;

void shortest_path(int s)
{
  for(int i = 0; i < V; i++) d[i] = INF;
  d[s] = 0;
  while(true)
  {
    bool update = false;
    for(int i = 0; i < E; i++)
    {
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
      {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if(!update) break;
  }
}
*********************************************************************/

/*****************************最短路径****************************************
void dijkstra(int s)
{
  fill(d,d + V,INF);
  fill(used,used + V; false);
  d[s] =0;
  while(true)
  {
    int v = -1;
    for(int u = 0; u < V; u++)
    {
      if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    if(v == -1) break;
    used[v] = true;

    for(int u = 0; u < V; u++) d[u] = min(d[u],d[v] + cost[v][u]);
  }
}


void warshall_floyd()
{
  for(int k = 0; k < V; k++)
  {
    for(int i = 0; i < V; i++)
    {
      for(itn j = 0; j < V; j++)
      {
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
      }
    }
  }
}
************************************************************************/

/************************最小生成树***************************************
int prim()
{
  for(int i = 0; i < V; i++)
  {
    mincost[i] = INF;
    used[i] = false;
  }
  mincost[0] = 0;
  int res = 0;
  while(true)
  {
    int v = -1;
    for(int u = 0; u < V; u++)
    {
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }
    if(v == -1) break;
    used[v] = true;
    res += mincost[v];
    for(int u = 0; u < V; u++) mincost[u] = min(mincost[u],cost[v][u]);
  }
  return res;
}
*************************************************************************/

/*********************************************
int gcd(int a,int b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

bool isPrime(int n)
{
  for(int i = 2; i * i <= n; i++)
  {
    if(n % i == 0) return false;
  }
  return n != 1;
}
*************************************************/

int main()
{
  int a,b;
    cin >> a >> b;
    cout << a+b << endl;
}
