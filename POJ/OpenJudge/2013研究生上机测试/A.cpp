#include <cstdio>
#include <cstring>

int n;
int a[10010];

void solve()
{
  int ans = 0;
  int d = n;
  int k = 1;
  a[0] = 0;
  for(int i = 1; i <= 10010; i++)
  {
    for(int j = 0; j < i; j++)
    {
      a[k] = a[k - 1] + i;
      k++;
      if(k == 10001) return;
    }
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  //memset(a, 0, sizeof(a));
  solve();
  while(scanf("%d",&n) && n != 0)
  {
    printf("%d %d\n",n,a[n]);
  }
}
