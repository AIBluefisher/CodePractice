#include <cstdio>

#define MAXN 30
int n,a;
int mem[MAXN];

int solve(int i)
{
  if(mem[i] != 0) return mem[i];
  else
    return mem[i] = solve(i - 2) + solve(i - 1);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);
  mem[0] = 1;
  mem[1] = 1;
  while(n--)
  {
    scanf("%d",&a);
    printf("%d\n",solve(a - 1));
    
  }
}
