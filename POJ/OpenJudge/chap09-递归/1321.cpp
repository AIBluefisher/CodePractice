//status: undo
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 10
int n,k;
char a[MAXN][MAXN];
int used[MAXN];
int ans;

void solve(int i)
{
  if(i <= n)
  {
    int num = 0;
    for(int j = 0; j < n; j++)
    {
      if(used[j]) num++;
    }
    if(num == k)
    {
      ans++;
      return;
    }
    for(int j = 0; j < n; j++)
    {
      if(!used[j] && a[i][j] == '.')
      {
        used[j] = 1;
        solve(i + 1);
        used[j] = 0;
      }
    }
  }
  return;
}

int main()
{
  freopen("in.txt","r",stdin);
  while(cin >> n >> k && (n != -1 || k != -1))
  {
    memset(used,0,sizeof(used));
    ans = 0;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    solve(0);
    printf("%d\n",ans);
  }
}
