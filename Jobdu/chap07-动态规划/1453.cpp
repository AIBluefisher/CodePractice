#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 110
#define INF 0x7fffffff
int t;
int n;
int a[MAXN];

void solve()
{
  memset(dp,0,sizeof(dp));

}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&t);
  for(int kase = 1; kase <= t; kase++)
  {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    printf("Case %d: ",kase);
    solve();
  }

}
