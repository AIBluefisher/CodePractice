#include <cstdio>

int p,e,i,d;

void solve()
{
  int num = 1;
  int j;
  for(j = d + 1; j < 21252; j++)
  {
    if((j - p) % 23 == 0) break;
  }
  for(; j < 21252; j += 23)
  {
    if((j - e) % 28 == 0) break;
  }
  for(; j < 21252; j += 23 * 28)
  {
    if((j - i) % 33 == 0) break;
  }
  printf("the next triple peak occurs in %d days.\n",j - d);
}

int main()
{
  freopen("in.txt","r",stdin);
  int t = 1;
  while(scanf("%d%d%d%d",&p,&e,&i,&d) && (p != -1 || e != -1 || i != -1 || d != -1))
  {
    printf("Case %d: ",t++);
    solve();
  }
}
