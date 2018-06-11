#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 210


void solve(char* str)
{
  int len = strlen(str);
  for(int i=0; i < len; i++)
  {
    if('A' <= str[i] && str[i] <= 'Z' )
    {
      if(str[i] <= 'E') printf("%c",str[i] + 21);
      else printf("%c",str[i] - 5);
    }
    else printf("%c",str[i]);
  }
  puts("");
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  char str[MAXN];
  char s[MAXN],e[4];

    gets(str);
    //printf("str[0]:%c",s[0]);
    //puts(s);
    solve(str);
}
