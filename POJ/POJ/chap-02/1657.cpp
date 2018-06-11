#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int T;
char s[2],t[2];
int xx,yy,x,y;

void king()
{
  int min;
  if(x == 0) min = y;
  if(y == 0) min = x;
  if(x == y) min = x;
  else min = max(x,y);
  printf("%d ",min);
}

void queen()
{
  int min;
  if(x == 0 && y == 0) min = 0;
  else
  {
    if(x == 0 || y == 0 || x == y) min = 1;
    else min = 2;
  }
  printf("%d ",min);
}

void car()
{
  int min;
  if(x == 0 && y == 0) min = 0;
  else
  {
    if(x == 0 || y == 0) min = 1;
    else min = 2;
  }
  printf("%d ",min);
}

void elephant()
{
  int min;
  if((x == 0 && y%2 == 1) || (y == 0 && x%2 == 1)) puts("Inf");
  else if(x == 0 & y == 0)
  {
    min = 0;
    printf("%d\n",min);
  }
  else
  {
    if((x == 0 && y%2 == 0) || (y == 0 && x%2 == 0)) min = 2;
    if(x == y) min = 1;
    printf("%d\n",min);
  }

}

void solve()
{
  king();
  queen();
  car();
  elephant();
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&T);
  while(T--)
  {
    scanf("%s%s",s,t);

    xx = s[0] - t[0];
    yy = s[1] - t[1];
    x = abs(xx);
    y = abs(yy);

    solve();
  }

}
