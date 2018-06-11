//百练 id: 1298
#include <cstdio>
#include <cstring>

#define MAXN 110
char str[MAXN];
char start[10],end[4];
char map[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";

void solve()
{
  int len = strlen(str);
  for(int i = 0; i < len; i++)
  {
    if('A' <= str[i] && str[i] <= 'Z') printf("%c",map[str[i] - 'A']);
    else printf("%c",str[i]);
  }
  puts("");
}

int main()
{
  while(gets(start) && (strcmp(start,"START") == 0))
  {
    gets(str);
    solve();
    gets(end);
  }
}
