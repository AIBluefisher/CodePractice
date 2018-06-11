//百练id: 1579
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100
int a,b,c;
int w[MAXN][MAXN][MAXN];

int solve(int a,int b,int c)
{
  if(a <= 0 || b <= 0 || c <= 0) return w[0][0][0] = 1;
  if(w[a][b][c]) return w[a][b][c];
  else if(a > 20 || b > 20 || c > 20) return w[20][20][20] = solve(20,20,20);
  else if(a < b && b < c)
  {
    return w[a][b][c] = solve(a,b,c - 1) + solve(a,b - 1,c - 1) - solve(a,b - 1,c);
  }
  else
  {
    return w[a][b][c] = solve(a - 1,b,c) + solve(a - 1,b - 1,c) + solve(a - 1,b,c - 1) - solve(a - 1,b - 1,c - 1);
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  memset(w,0,sizeof(0));
  while(scanf("%d%d%d",&a,&b,&c) && (a != -1 || b != -1 || c != -1))
  {
    printf("w(%d, %d, %d) = %d\n",a,b,c,solve(a,b,c));
  }
}
