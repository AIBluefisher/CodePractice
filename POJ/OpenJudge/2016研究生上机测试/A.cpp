// 百练 id:2703
#include <cstdio>

float n;
int t;

int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%f",&n);
    float t1 = n / 1.2;
    float t2 = n / 3.0 + 50;
    if(t1 > t2) puts("Bike");
    else if(t1 < t2) puts("Walk");
    else puts("All");
  }

}
