#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 20
int a[MAXN];

void solve(int n)
{
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if((a[j] / a[i] == 2) && (a[j] % a[i] == 0)) ans++;
    }
  }
  printf("%d",ans);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  int i = 0;
  while(scanf("%d",&a[i]) && a[i]!=0) i++;
  solve(i);

}
