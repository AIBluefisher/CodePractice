#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 210
char num1[MAXN],num2[MAXN];
int integ1[MAXN],integ2[MAXN],ans[MAXN];

void solve()
{
  int carry = 0;
  int l1 = strlen(num1), l2 = strlen(num2);
  int k = max(l1, l2);

  int j = 0;
  for(int i = l1 - 1; i >= 0; i--) integ1[j++] = num1[i] - '0';
  j = 0;
  for(int i = l2 - 1; i >= 0; i--) integ2[j++] = num2[i] - '0';

  int carrry = 0;
  for(int i = 0; i < MAXN; i++)
  {
    ans[i] = integ1[i] + integ2[i];
    if(integ1[i] >= 10)
    {
      ans[i] -= 10;
      ans[i + 1]++;
    }
  }

  bool so = false;
  for(int i = MAXN; i >= 0; i--)
  {
    if(so) printf("%d",ans[i]);
    else if(ans[i])
    {
      printf("%d",ans[i]);
      so = true;
    }
  }
}


int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  memset(integ1,0,sizeof(integ1));
  memset(integ2,0,sizeof(integ2));
  memset(ans,0,sizeof(ans));

  scanf("%s%s",num1,num2);
  solve();
}
