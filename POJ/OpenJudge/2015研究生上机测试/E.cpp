#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10010
#define INF 10000000
int n;
int a,b;
int used[MAXN];
int mmin = INF,mmax = 0;

void cover()
{
  for(int i = a; i <= b; i++) used[i] = 1;
}

void solve()
{
  for(int i = mmin; i <= mmax; i++) 
  {
    if(!used[i])
    {
      printf("no");
      return;
    }
  }
  printf("%d %d",mmin,mmax);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  memset(used,0,sizeof(used));
  scanf("%d",&n);

  while(n--)
  {
    scanf("%d%d",&a,&b);
    mmin = min(mmin,a);
    mmax = max(mmax,b);
    cover();
  }
  solve();
}
