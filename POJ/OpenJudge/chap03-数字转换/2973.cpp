#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 32
char s[MAXN];
int num[MAXN];

void solve()
{
  int sum = 0;
  int len = strlen(s);
  int j = 0;
  for(int i = len - 1; i >= 0; i--)  num[j++] = s[i] -'0';
  for(int i = 0; i < len; i++)
  {
    sum += num[i] * (pow(2, i + 1) - 1);
  }
  printf("%d\n",sum);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%s",s) && s[0] != '0')
  {
    solve();
  }
}
