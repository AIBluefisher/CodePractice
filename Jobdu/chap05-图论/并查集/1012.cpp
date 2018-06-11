#include <cstdio>
#include <cstring>

typedef struct
{
  int parent;
  int rank;
}UFSTree;

#define MAXN 1010
int N,M;
int x,y;
UFSTree t[MAXN];
int a[MAXN];

void init(UFSTree t[])
{
  for(int i = 1; i <= N; i++)
  {
    t[i].rank = 0;
    t[i].parent = i;
  }
}

int findRoot(UFSTree t[], int x)
{
  if(t[x].parent == x) return x;
  else
    return findRoot(t, t[x].parent);
}

void uni(UFSTree t[], int x, int y)
{
  int r1 = findRoot(t, x);
  int r2 = findRoot(t, y);

  if(t[r1].rank > t[r2].rank) t[r2].parent = r1;
  else
  {
    t[r1].parent = r2;
    if(t[r1].rank == t[r2].rank) t[r2].rank++;
  }
}

void solve()
{
  int ans = 0;
  memset(a,0,sizeof(a));
  for(int i = 1; i <= N; i++) a[findRoot(t, i)]++;
  for(int i = 1; i <= N; i++)
  {
    if(a[i]) ans++;
  }
  printf("%d\n",ans - 1);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d",&N) && N)
  {
    scanf("%d",&M);
    init(t);
    for(int i = 0; i < M; i++)
    {
      scanf("%d%d",&x,&y);
      uni(t, x, y);
    }
    solve();
  }
}
