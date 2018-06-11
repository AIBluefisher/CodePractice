#include <cstdio>
#include <cmath>

int n;

void solve()
{
  for(int i = 0; i < n; i++)
  {
    if(pow(2,i) >= n)
    {
      printf("%d",i);
      return;
    }
  }
}

int main()
{
  scanf("%d",&n);
  solve();
}
