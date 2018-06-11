/**************************************************************
    Problem: 1109
    User: 陈煜
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:1032 kb
****************************************************************/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int parent;
  int rank;
}UFSTree;
#define MAXN 1010
int n,m;
int x,y;
UFSTree t[MAXN];
int sum[MAXN];

void init()
{
  for(int i = 1; i <= n; i++)
  {
    t[i].rank = 0;
    t[i].parent = i;
  }
}

int findRoot(int x)
{
  if(t[x].parent == x) return x;
  else return findRoot(t[x].parent);
}

void uni(int x,int y)
{
  int t1 = findRoot(x);
  int t2 = findRoot(y);

  if(t[t1].rank > t[t2].rank) t[t2].parent = t1;
  else
  {
    t[t1].parent = t2;
    if(t[t1].rank == t[t2].rank) t[t2].rank++;
  }
}

void solve()
{
  int ans = 0;
  memset(sum,0,sizeof(sum));
  for(int i = 1; i <= n; i++)
  {
    sum[findRoot(i)]++;
  }
  for(int i = 1; i <= n; i++) ans = max(ans,sum[i]);
  if(ans != n) puts("NO");
  else puts("YES");
}

int main()
{
  while(scanf("%d%d",&n,&m) && (n != 0))
  {
    init();
    for(int i = 0; i < m; i++)
    {
      scanf("%d%d",&x,&y);
      uni(x,y);
    }
    solve();
  }
}
