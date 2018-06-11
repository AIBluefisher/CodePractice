#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 30
int N;

typedef struct
{
  char name[MAXN];
  int finalAve,claComment;
  char isStu, isWest;
  int papers;
  int rew;
}Stu;
Stu stu[110];

void reward(Stu& stu)
{
  stu.rew = 0;
  if(stu.finalAve > 80 && stu.papers >= 1) stu.rew += 8000;
  if(stu.finalAve > 85 && stu.claComment > 80) stu.rew += 4000;
  if(stu.finalAve > 90) stu.rew += 2000;
  if(stu.finalAve > 85 && stu.isWest == 'Y') stu.rew += 1000;
  if(stu.claComment > 80 && stu.isStu == 'Y') stu.rew += 850;
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&N);
  int mm = 0;
  int sum = 0;
  int ind = 0;
  for(int i = 0; i < N; i++)
  {
    cin >> stu[i].name >> stu[i].finalAve >> stu[i].claComment >> stu[i].isStu >> stu[i].isWest >> stu[i].papers;

    reward(stu[i]);

    if(mm < stu[i].rew)
    {
        ind = i;
        mm = stu[i].rew;
    }
    sum += stu[i].rew;
  }
  printf("%s\n%d\n%d\n",stu[ind].name,stu[ind].rew,sum);
}
