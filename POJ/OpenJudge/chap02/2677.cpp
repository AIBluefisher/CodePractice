#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 110
int N;
int a[MAXN][MAXN];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void solve()
{
  int l = 0, s = 0;
  bool isEdge;

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      isEdge = true;
      if(a[i][j] <= 50)
      {
        s++;
        for(int k = 0; k < 4; k++)
        {
          int ox = i + dx[k];
          int oy = j + dy[k];
          if(0 <= ox && ox < N && 0 <= oy && oy < N && a[ox][oy] > 50) isEdge = false;
        }
        if(!isEdge) l++;
        else if(i + 1 >= N || i - 1 < 0 || j - 1 < 0 || j + 1 >= N) l++;
      }
    }
  }
  cout << s << " " << l;
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  cin >> N;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++) cin >> a[i][j];
  }
  solve();
}
