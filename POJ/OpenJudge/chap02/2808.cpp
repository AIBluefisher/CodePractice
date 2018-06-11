#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> coordinate;

#define MAXN 110
int L,M;
int isTree[10010];
coordinate pos[MAXN];

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d%d",&L,&M);
  memset(isTree,0,sizeof(isTree));
  for(int i = 0; i < M; i++)
  {
    scanf("%d%d",&pos[i].first,&pos[i].second);
    for(int j = pos[i].first; j <= pos[i].second; j++) isTree[j] = 1;
  }

  int num = 0;
  for(int i = 0; i <= L; i++)
  {
    if(isTree[i] == 0) num++;
  }
  printf("%d",num);
}
