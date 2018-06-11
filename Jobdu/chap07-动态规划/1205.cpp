#include <cstdio>
#include <cstring>

int N;
long long int a[100];

int main()
{
  a[1] = 1;
  a[2] = 2;

  for(int i = 3; i <= 90; i++)
  {
    a[i] = a[i - 1] + a[i - 2];
  }
  while(scanf("%d",&N) != EOF)
  {
    printf("%lld\n",a[N]);
  }
}
