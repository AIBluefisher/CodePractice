#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct
{
  double w;
  double v;
  double vpk;
}goods;
#define MAXN 110
int k;
double W;
int s;
goods g[MAXN];

bool cmp(goods g1,goods g2)
{
  return g1.vpk > g2.vpk;
}

void solve()
{
  sort(g,g + s,cmp);
  double ans = 0;
  for(int i = 0; i < s; i++)
  {
    if(g[i].w <= W)
    {
      ans += g[i].v;
      W = W - g[i].w;
    }
    else
    {
      ans += W * g[i].vpk;
      break;
    }
  }
  printf("%.2f\n",ans);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&k);
  while(k--)
  {
    scanf("%lf",&W);
    scanf("%d",&s);
    for(int i = 0; i < s; i++)
    {
      scanf("%lf%lf",&g[i].w,&g[i].v);
      g[i].vpk = g[i].v / g[i].w;
    }
    solve();
  }
}
