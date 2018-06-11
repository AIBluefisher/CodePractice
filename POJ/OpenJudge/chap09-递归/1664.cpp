#include <cstdio>

int t;
int M,N;

int solve(int x,int y)
{
  if(y == 1 || x == 0) return 1;
  else if(x < y) return solve(x,x);
  else return solve(x,y - 1) + solve(x - y,y);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&M,&N);

    printf("%d\n",solve(M,N));
  }
}
