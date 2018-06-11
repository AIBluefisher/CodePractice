#include <cstdio>
#include <cstring>

#define MAXN 30
int s;
char ss[MAXN];
int str[MAXN];
char a1[] = {"- -- -----"};
char a2[] = {"|   ||| ||"};
char a3[] = {"|||||  |||"};
char a4[] = {"  ----- --"};
char a5[] = {"| |   | | "};
char a6[] = {"|| |||||||"};
char a7[] = {"- -- -- --"};

void solve()
{
  int len = strlen(ss);
  for(int i = 0; i < len; i++) str[i] = ss[i] - '0';

  for(int i = 0; i < len; i++)
  {
    printf(" ");
    for(int j = 1; j <= s; j++)
    {
      printf("%c",a1[str[i]]);
    }
    printf("  ");
  }
  puts("");

  for(int j = 1; j <= s; j++)
  {
    for(int i = 0; i < len; i++)
    {
      printf("%c",a2[str[i]]);
      for(int k = 1; k <= s; k++) printf(" ");
      printf("%c ",a3[str[i]]);
    }
    puts("");
  }

  for(int i = 0; i < len; i++)
  {
    printf(" ");
    for(int j = 1; j <= s; j++)
    {
      printf("%c",a4[str[i]]);
    }
    printf("  ");
  }
  puts("");

  for(int j = 1; j <= s; j++)
  {
    for(int i = 0; i < len; i++)
    {
      printf("%c",a5[str[i]]);
      for(int k = 1; k <= s; k++) printf(" ");
      printf("%c ",a6[str[i]]);
    }
    puts("");
  }

  for(int i = 0; i < len; i++)
  {
    printf(" ");
    for(int j = 1; j <= s; j++)
    {
      printf("%c",a7[str[i]]);
    }
    printf("  ");
  }
  puts("\n");
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d%s",&s,ss) && (s != 0 || strcmp(ss,"0") != 0))
  {
    solve();
  }
}
