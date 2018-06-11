#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 10000001

typedef struct
{
  int parent;
  //int rank;
}UFSTree;

int n;
int A,B;
UFSTree t[MAXN];
int a[MAXN];

void init()
{
  for(int i = 1; i <= MAXN; i++)
  {
    //t[i].rank = 0;
    t[i].parent = i;
    a[i] = 0;
  }
}

int findRoot(int i)
{
  if(t[i].parent == i) return i;
  return findRoot(t[i].parent);
}

void uni(int x, int y)
{
  int r1 = findRoot(x);
  int r2 = findRoot(y);

  t[r1].parent = r2;
  /*
  if(t[r1].rank > t[r2].rank) t[r2].parent = r1;
  else
  {
    t[r1].parent = r2;
    if(t[r1].rank == t[r2].rank) t[r2].rank++;
  }
  */
}

void solve()
{
  int ans = 0;
  int temp;
  for(int i = 1; i <= MAXN; i++)
  {
    temp = findRoot(i);
    a[temp]++;
    ans = max(ans, a[temp]);
  }
  printf("%d\n",ans);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d",&n) != EOF)
  {
    init();
    while(n--)
    {
      scanf("%d%d",&A,&B);
      uni(A,B);
    }
    solve();
  }
}
