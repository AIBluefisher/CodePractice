#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 1000
int R,C;
char str[MAXN];
int s[MAXN];
int mat[30][30];
int used[30][30];
char map[][6] = {"00001","00010","00011","00100","00101","00110","00111",
                  "01000","01001","01010","01011","01100","01101","01110",
                  "01111","10000","10001","10010","10011","10100","10101",
                  "10110","10111","11000","11001","11010"};
int turn,count;

void dfs(int x,int y)
{
  if(count == R * C) return;
  mat[x][y] = s[count];
  used[x][y] = 1;
  count++;

  if(turn == 1 && (y + 1 == C || used[x][y + 1])) turn = 2;
  if(turn == 2 && (x + 1 == R || used[x + 1][y])) turn = 3;
  if(turn == 3 && (y - 1 < 0 || used[x][y - 1])) turn = 4;
  if(turn == 4 && (x - 1 < 0 || used[x - 1][y])) turn = 1;

  if(turn == 1) dfs(x,y + 1);
  if(turn == 2) dfs(x + 1,y);
  if(turn == 3) dfs(x,y - 1);
  if(turn == 4) dfs(x - 1,y);
}

void solve()
{
  memset(mat,0,sizeof(0));
  memset(used,0,sizeof(0));

  int len = strlen(str);
  int k = 0;
  for(int i = 0; i < len; i++)
  {
    if(str[i] != ' ')
    {
      for(int j = 0; j < 5; j++) s[k++] = map[str[i] - 'A'][j] - '0';
    }
    else
    {
      for(int j = 0; j < 5; j++) s[k++] = 0;
    }
  }

  count = 0;
  turn = 1;
  dfs(0,0);

  for(int i = 0; i < R; i++)
  {
    for(int j = 0; j < C; j++) printf("%d",mat[i][j]);
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  scanf("%d%d",&R,&C);
  char b;
  scanf("%c",&b);
  gets(str);
  solve();
}
