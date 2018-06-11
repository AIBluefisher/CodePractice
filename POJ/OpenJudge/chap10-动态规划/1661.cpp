#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 1010
#define INF 100000000
typedef struct
{
  int l,r;
  int h;
}stage;

int t;
int N,X,Y,MAX;
stage s[MAXN];
int dp[MAXN][MAXN];

bool cmp(stage s1,stage s2)
{
  return s1.h > s2.h;
}

void solve()
{
  sort(s,s+N,cmp);
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {

    }
  }

  int ans = INF;
  for(int i = 0; i < N; i++)
  {
    ans = min(ans,dp[N-1][i]);
  }
  printf("%d\n",ans);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d%d",&N,&X,&Y,&MAX);
    for(int i = 0; i < N; i++) scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].h);

    solve();
  }

}
