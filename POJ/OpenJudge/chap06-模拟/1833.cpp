#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 2000
int m;
int n,k;
int a[MAXN];

void solve()
{
  for(int i = 0; i < k; i++) next_permutation(a, a + n);
  for(int i = 0; i < n; i++) printf("%d ",a[i]);
  puts("");
}

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

  scanf("%d",&m);
  while(m--)
  {
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
    }
    solve();
  }
}
