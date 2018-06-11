#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define MAXN 34000
int n;
int a;
int ans;
int dp[MAXN];

void primeFactor(int n)
{
  map<int, int> res;
  for(int i = 2; i * i <= n; i++)
  {
    while(n % i == 0)
    {
      res[n]++;
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  //return res;
  map<int, int>::iterator ite;
  for(ite = res.begin(); ite != res.end(); ite++)
  {
    printf("%d: %d\n",ite->first,ite->second);
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);
  memset(dp,0,sizeof(dp));
  while(n--)
  {
    scanf("%d",&a);
    primeFactor(a);
    puts("");
  }
}
