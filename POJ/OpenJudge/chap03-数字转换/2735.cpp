#include <cstdio>
#include <cmath>
int a;

void solve(int a)
{
  int num = 0;
  int temp;
  int i = 0;
  while(a)
  {
    temp = a % 10;
    num += temp * pow(8,i++);
    a /= 10;
  }
  printf("%d",num);
}

int main()
{
  scanf("%d",&a);
  solve(a);
}
