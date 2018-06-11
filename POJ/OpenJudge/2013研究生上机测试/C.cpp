//百练 id: 2406
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000010
char str[MAXN];

void solve()
{
  int len = strlen(str);
  char temp[MAXN];
  for(int i = 1; i <= len; i++)
  {
    if((i & 1 == 0) && (len & 1 == 1)) break;
    if(i > (len >> 1))
    {
      printf("%d\n",1);
      return;
    }
    memset(temp,0,sizeof(0));
    for(int j = 1; j <= len; j ++)
    {
      strncat(temp,str,i);
      if(strncmp(temp,str,i * j) != 0) break;
      if((i * j == len) && strcmp(temp,str) == 0)
      {
        printf("%d\n",j);
        return;
      }
    }
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%s",str) && strcmp(str,".") != 0)
  {
    solve();
  }
}
