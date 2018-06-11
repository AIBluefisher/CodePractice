#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 10
char p[MAXN],q[MAXN],r[MAXN];
int num1[MAXN],num2[MAXN],sum[MAXN];

int getSum(int* num, int len, int c)
{
  int s = 0;
  for(int i = len - 1; i >= 0; i--)
  {
    if(num[i] >= c) return -1;
    s += num[i] * pow(c, len - i - 1);
  }
  return s;
}

void solve()
{
  int len1 = strlen(p);
  int len2 = strlen(q);
  int len3 = strlen(r);

  for(int i = 0; i < len1; i++) num1[i] = p[i] - '0';
  for(int i = 0; i < len2; i++) num2[i] = q[i] - '0';
  for(int i = 0; i < len3; i++) sum[i] = r[i] - '0';

  int s1, s2, s3;
  for(int i = 2; i < 17; i++)
  {
    s1 = getSum(num1, len1, i);
    s2 = getSum(num2, len2, i);
    s3 = getSum(sum, len3, i);
    if(s1 == -1 || s2 == -1 || s3 == -1) continue;
    if(s1 * s2 == s3)
    {
      printf("%d",i);
      return;
    }
  }
  printf("0");
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%s%s%s",p,q,r);
  solve();
}
