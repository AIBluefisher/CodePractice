//百练 id: 2677
#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 110
int N;
int a[MAXN][MAXN];
int s = 0, c = 0;

void solve()
{
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(a[i][j] <= 50)
      {
        if((i == 0) || (j == 0) || (i == N - 1) || (j == N - 1)) c++;
        else
        {
          if((a[i - 1][j] > 50) || (a[i + 1][j] > 50) || (a[i][j - 1] > 50) || (a[i][j + 1] > 50)) c++;
        }
      }
    }
  }
  printf("%d %d",s,c);
}

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

  cin >> N;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      cin >> a[i][j];
      if(a[i][j] <= 50) s++;
    }
  }
  solve();
}
