#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXN 10010
int n;
char a[MAXN];

long long int t2d(char* a)
{
  int len = strlen(a);
  long long int num = 0;
  int nn;
  for(int i = len - 1; i >= 0; i--)
  {
    nn = a[i] - '0';
    num += nn * pow(2,len - 1 - i);
  }
  return num;
}

void solve(long long int d)
{
  int temp;
  if(d == 0) return;
  else
  {
    solve(d / 16);
    temp = d % 16;
    if(0 <= temp && temp <= 9) printf("%d",temp);
    else printf("%c",55 + temp);
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);
  long long int d;
  while(n--)
  {
    scanf("%s",a);
    d = t2d(a);
    if(d == 0) printf("0");
    else solve(d);
    puts("");
  }
}
