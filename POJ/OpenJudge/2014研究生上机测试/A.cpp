//百练 id: 4001
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 100001
#define INF 0x7fffffff
int N,K;
int d[MAXN];
int dx[] = {-1, 1};

int bfs()
{
  for(int i = 0; i < MAXN; i++) d[i] = INF;
  queue<int> qu;
  qu.push(N);
  d[N] = 0;
  while(qu.size())
  {
    int t = qu.front();qu.pop();
    if(t == K) break;
    int ox;
    for(int i = 0; i < 3; i++)
    {
      if(i == 2) ox = t * 2;
      else ox = t + dx[i];
      if(0 <= ox && ox < MAXN && d[ox] == INF)
      {
        qu.push(ox);
        d[ox] = d[t] + 1;
      }
    }
  }
  return d[K];
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  scanf("%d%d",&N,&K);
  printf("%d",bfs());
}
