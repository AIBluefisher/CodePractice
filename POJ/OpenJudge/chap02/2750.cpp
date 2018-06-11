#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int a;
void solve()
{
  int min,max;
  if((a%2)!=0) printf("0 0");
  else
  {
    max = a / 2;
    min = a / 4 + (a % 4) / 2;
    printf("%d %d",min,max);
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&a);
  solve();
}
