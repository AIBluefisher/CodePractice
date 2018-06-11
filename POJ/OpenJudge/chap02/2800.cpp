#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 330

int cou[26];

void solve()
{
  int m = 0;
  for(int i = 0; i < 26; i++) m = max(m,cou[i]);

  int num;
  for(int j = 0; j < m; j++)
  {
    for(int i = 0; i < 26; i++)
    {
      num = cou[i] - m;
      if(num < 0)
      {
        printf("  ");
        cou[i]++;
      }
      else printf("* ");
    }
    printf("\n");
  }
  char first = 'A';
  for(int i = 0; i < 26; i++) printf("%c ",first++);
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  int i = 0;
  char c;
  while(scanf("%c",&c)!=EOF)
  {
    //printf("%c",c);
    if('A' <= c && c <= 'Z')
    {
      //printf("%d ",c - 'A');
      cou[c - 'A']++;
    }
  }
  solve();
}
