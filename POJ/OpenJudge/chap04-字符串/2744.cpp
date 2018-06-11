#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 110
int t;
int n;
char str[MAXN][MAXN];

void solve()
{
  
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
      scanf("%s",str[i]);
      solve();
    }
  }

}
