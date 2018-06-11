#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 110
int n;
float a[MAXN];


int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);
  float sum = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%f",&a[i]);
    sum += a[i];
  }
  printf("%.2f",sum / n);

}
