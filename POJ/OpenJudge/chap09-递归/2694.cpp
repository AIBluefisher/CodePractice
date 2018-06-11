#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cmath>
using namespace std;

double solve()
{
  char a[10];
  scanf("%s",a);
  switch (a[0])
  {
    case '+': return solve() + solve();break;
    case '-': return solve() - solve();break;
    case '*': return solve() * solve();break;
    case '/': return solve() / solve();break;
    default: return atof(a);break;
  }
}


int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  printf("%f",solve());
}
