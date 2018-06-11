#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int a;

void solve()
{
  //bool flag = true;
  if(a % 4 != 0 || a % 3200 == 0) printf("N");

  else if( a % 100 == 0 && a % 400 != 0) printf("N");

  else printf("Y");
}

int main()
{

  scanf("%d",&a);
  solve();

}
