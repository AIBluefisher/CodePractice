//百练 id: 2748
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[10];
int len;


void solve()
{
  len = strlen(str);
  sort(str,str + len);
  puts(str);
  while(next_permutation(str,str + len))
  {
    puts(str);
  }
}

int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

  scanf("%s",str);
  solve();
}
