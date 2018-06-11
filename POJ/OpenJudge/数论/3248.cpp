#include <cstdio>

int a,b;

int gcd(int a,int b)
{
  if(b == 0) return a;
  return gcd(b,a % b);
}

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(scanf("%d%d",&a,&b) != EOF)
  {
    printf("%d\n",gcd(a,b));
  }
}
