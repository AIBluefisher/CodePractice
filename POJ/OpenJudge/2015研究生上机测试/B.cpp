//百练id: 1488
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 1000000
char str[MAXN];
int k = 0;

void solve()
{
  int len = strlen(str);
  for(int i = 0; i < len; i++)
  {
    if(str[i] == '\"')
    {
      k++;
      if(k % 2 == 1) printf("\`\`");
      if(k % 2 == 0) printf("\'\'");
    }
    else printf("%c",str[i]);
  }
  puts("");
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(gets(str))
  {
    solve();
  }
}
