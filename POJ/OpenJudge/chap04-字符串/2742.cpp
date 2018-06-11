#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXN 1010

int n;
char str[MAXN];
int v[30];


void solve()
{
  int len = strlen(str);
  for(int i = 0; i < len; i++)
  {
    int index = str[i] - 'a';
    v[index]++;
  }
  int max = 0;
  int alpha = 0;
  for(int i = 0; i < 26; i++)
  {
    if(max < v[i])
    {
      max = v[i];
      alpha = i + 'a';
    }
  }
  printf("%c %d\n",alpha,max );
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);
  while(n--)
  {
    scanf("%s",str);
    for(int i = 0; i < 26; i++) v[i] = 0;
    
    solve();
  }
}
