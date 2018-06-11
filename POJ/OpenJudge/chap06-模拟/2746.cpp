#include <cstdio>

int n,m;

void solve()
{
  int s = 0;
  for(int i = 2; i <= n; i++) s = (s + m) % i;
  printf("%d\n",s + 1);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d%d",&n,&m) && (n != 0 || m != 0))
  {
    solve();
  }
}
