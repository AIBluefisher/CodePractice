#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct
{
  char in[1000];
  char fra[1000];
  int len;
}Num;

#define MAXN 10010
int n;
Num num[MAXN];
char str[2000];

void cut(int i)
{
  int len = strlen(str);
  int k = 0;
  bool frac = false;
  for(int j = 0; j < len; j++)
  {
    if(!frac) num[i].in[k++] = str[j];
    if(frac) num[i].fra[k++] = str[j];
    if(str[j] == '.')
    {
      num[i].in[k] = '\0';
      k = 0;
      frac = true;
    }
  }
  num[i].fra[k] = '\0';
  num[i].len = strlen(num[i].in);
}

void solve()
{
  int maxLen = 0;
  for(int i = 0; i < n; i++) maxLen = max(maxLen, num[i].len);

  int dis = 0;
  for(int i = 0; i < n; i++)
  {
    dis = maxLen - num[i].len;
    for(int j = 0; j < dis; j++) printf(" ");
    printf("%s%s\n",num[i].in,num[i].fra);
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s",str);
    cut(i);
  }
  solve();
}
