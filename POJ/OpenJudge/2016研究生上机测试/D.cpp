//百练 id: 2972
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAXN 20
char p[MAXN],q[MAXN],r[MAXN];
int num1[MAXN],num2[MAXN],sum[MAXN];

int getSum(int* num, int len, int c)
{
  int ss = 0;
  for(int i = 0; i < len; i++)
  {
    if(num[i] >= c) return -1;
    ss += num[i] * pow(c,i);
  }
  return ss;
}

void solve()
{
  int len1 = strlen(p);
  int len2 = strlen(q);
  int len3 = strlen(r);

  for(int i = 0; i < len1; i++) num1[len1 - i - 1] = p[i] - '0';
  for(int i = 0; i < len2; i++) num2[len2 - i - 1] = q[i] - '0';
  for(int i = 0; i < len3; i++) sum[len3 - i - 1] = r[i] - '0';

  for(int i = 2; i <= 16; i++)
  {
    int n1 = getSum(num1, len1, i);
    int n2 = getSum(num2, len2, i);
    int s = getSum(sum, len3, i);
    if(n1 == -1 || n2 == -1 || s == -1) continue;
    if(n1 * n2 == s)
    {
      printf("%d",i);
      return;
    }
  }
  printf("0");
}

int main()
{
  scanf("%s%s%s",p,q,r);
  solve();
}
