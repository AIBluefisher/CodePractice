#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1000010
int n;
int k;
int dp[MAXN];

int solve(int i)
{
  if(dp[i]) return dp[i];
  if(i == 1) return dp[i] = 1;
  if(i == 2) return dp[i] = 2;
  else return dp[i] = (solve(i - 2) + 2 * solve(i - 1)) % 32767;
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  memset(dp,0,sizeof(dp));
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d",&k);
    printf("%d\n",solve(k));
  }
}
