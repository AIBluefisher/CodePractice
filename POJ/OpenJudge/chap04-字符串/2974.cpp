#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100010
int n;
char str[MAXN][9];
char map[] = "2223334445556667777888999";
char temp[200];

int cmp(const void* str1, const void* str2)
{
  return (strcmp((char*)str1, (char*)str2));
};

void transfer(int m)
{
  int len = strlen(temp);
  int j = 0;
  for(int i = 0; i < len; i++)
  {
    if(j == 3)
    {
      str[m][j++] = '-';
      i--;
    }
    else if(temp[i] == '-') continue;
    else if('A' <= temp[i] && temp[i] <= 'Z') str[m][j++] = map[temp[i] - 'A'];
    else str[m][j++] = temp[i];
  }
  str[m][j] = '\0';
}

void solve()
{
  qsort(str, n, 9, cmp);
  int count = 1;
  bool flag = false;
  for(int i = 1; i < n; i++)
  {
    if(strcmp(str[i],str[i - 1]) == 0) count++;
    else if(strcmp(str[i],str[i - 1]) != 0 && count != 1)
    {
      printf("%s %d\n",str[i - 1],count);
      count = 1;
      flag = true;
    }
  }
  if(!flag) printf("No duplicates.\n");
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s",temp);
    transfer(i);
  }

/*
  qsort(str, n, 9, cmp);
  for(int i = 0; i < n; i++)
  {
    printf("%d:%s\n",i,str[i]);
  }*/

  solve();
}
