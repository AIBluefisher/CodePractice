#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100010
char s[MAXN],t[MAXN];

void solve()
{
  int sl = strlen(s);
  int tl = strlen(t);
  bool isFind = false;
  int pre = -2, cur = -1;
  for(int i = 0; i < sl; i++)
  {
    for(int j = 0; j < tl; j++)
    {
      if(s[i] == t[j])
      {
        pre = cur;
        cur = j;
        if(pre >= cur) isFind = false;
      }
    }
    if(!isFind)
    {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%s%s",s,t) != EOF)
  {
    solve();
  }

}
