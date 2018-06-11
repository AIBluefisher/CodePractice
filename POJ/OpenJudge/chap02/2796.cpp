#include <cstdio>

int a;
int m[6];

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&a);
  int sum = 0;
  for(int i=0;i<5;i++)
  {
    scanf("%d",m[i]);
    if(m[i]<a) sum+=m[i];
  }
  printf("%d",sum);
}
