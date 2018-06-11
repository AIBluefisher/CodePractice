#include <cstdio>

#define MAXN 1010
int n;
int a[MAXN][MAXN];

void solve()
{
  int x = 0, y = 0;
  bool isBreak = false;
  bool isCheck = false;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(a[i][j] == 0)
      {
        x++;
        isCheck = true;
      }
    }
    if(isCheck) break;
  }
  isCheck = false;
  x -= 2;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(a[j][i] == 0)
      {
        y++;
        isCheck = true;
      }
    }
    if(isCheck) break;
  }
  y -= 2;
  printf("%d",x * y);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++) scanf("%d",&a[i][j]);
  }
  solve();
}
