#include <cstdio>
using namespace std;

#define MAXN 34000
int n;
int aa;
int sum;

void dfs(int a,int i)
{
  if(a == 1) sum++;
  while(i <= a)
  {
    if(a % i == 0) dfs(a / i,i);
    i++;
  }
}

void solve()
{
  int ans = 1;
  for(int i = 2; i * i <= aa; i++)
  {
    sum = 0;
    if(aa % i == 0) dfs(aa / i,i);
    ans += sum;
  }
  printf("%d\n",ans);
}

int main()
{
  freopen("in.txt","r",stdin);

  scanf("%d",&n);
  while(n--)
  {
    scanf("%d",&aa);
    solve();
  }
}
