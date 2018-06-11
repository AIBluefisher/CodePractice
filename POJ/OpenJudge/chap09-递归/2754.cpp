#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXN 92
int n,b,pos[8],num;
int a[MAXN][8];

void queen(int i)
{
  if(i == 8)
  {
    for(int j = 0; j < 8; j++) a[num][j] = pos[j] + 1;
    num++;
    return;
  }

  int k;
  for(int j = 0; j < 8; j++)
  {
    for(k = 0; k < i; k++)
    {
      if(pos[k] == j || (k - i == pos[k] - j) || (i - k == pos[k] - j)) break;
    }
    if(k == i)
    {
      pos[k] = j;
      queen(i + 1);
    }
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  memset(a,0,sizeof(a));
  num = 0;
  scanf("%d",&n);
  queen(0);
  while(n--)
  {
    scanf("%d",&b);
    for(int i = 0; i < 8; i++) printf("%d",a[b-1][i]);
    puts("");
  }
}
