#include <cstdio>


int x,y;

void solve(int x,int y)
{
  if(x == y)
  {
    printf("%d",x);
    return;
  }
  else
  {
    if(x > y) return solve(x / 2,y);
    if(x < y) return solve(x,y / 2);
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d%d",&x,&y);
  solve(x,y);
}
