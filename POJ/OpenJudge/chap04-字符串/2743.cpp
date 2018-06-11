#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define MAXN 1010
char str1[MAXN],str2[MAXN];

void solve()
{
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  char s1[MAXN],s2[MAXN];
  int j = 0;
  for(int i = 0; i < len1; i++)
  {
    if(str1[i] != ' ')
    {
      s1[j++] = toupper(str1[i]);
    }
  }
  s1[j] = '\0';
  j = 0;
  for(int i = 0; i < len2; i++)
  {
    if(str2[i] != ' ')
    {
      s2[j++] = toupper(str2[i]);
    }
  }
  s2[j] = '\0';

  if(strcmp(s1,s2) == 0) printf("YES");
  else printf("NO");
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  gets(str1);
  gets(str2);
  solve();

}
