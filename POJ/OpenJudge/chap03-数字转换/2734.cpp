#include <cstdio>

int a;

void solve(int a)
{
  if(a == 0) return;
  else
  {
    solve(a / 8);
    printf("%d",a % 8);
  }
}

int main()
{
  scanf("%d",&a);
  if(a == 0) printf("0");
  else solve(a);
}
