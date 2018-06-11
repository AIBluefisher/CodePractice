// id :4121
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100010
int T;
int N;
int a[MAXN];
int dp[MAXN][MAXN];

void solve()
{
  
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&N);
    for(int i = 0; i < N; i++) scanf("%d",&a[i]);
    solve();
  }

}
