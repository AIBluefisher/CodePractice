#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int W,H;
char tiles[21][21];
int v[21][21];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int px,py;

int bfs(int x,int y)
{
  int num = 1;
  queue<P> q;
  //pair<int,int> p;
  q.push(P(x,y));
  v[x][y] == 1;

  while(!q.empty())
  {
    P p = q.front();
    q.pop();
    //cout << p.first << " " << p.second;
    for(int i=0;i<4;i++)
    {
        int ox = p.first + dx[i];
        int oy = p.second + dy[i];

        if(0 < x && x < H && 0 < y && y < W && tiles[ox][oy] != '#'
          && v[ox][oy] == 0)
        {
          q.push(P(ox,oy));
          v[ox][oy] = 1;
          num++;
        }
    }
  }
  return num;
}

void output(int w,int h)
{
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      printf("%c",tiles[i][j]);
    }
    printf("\n");
  }
}


int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(cin >> W >> H && (W!=0 && H!=0))
  {
    for(int i=0;i<H;i++)
    {
      for(int j=0;j<W;j++)
      {
        cin >> tiles[i][j];
        //cout << tiles[i][j];
        v[i][j] = 0;
        if(tiles[i][j]=='@')
        {
          px=i;
          py=j;
        }
      }
    }
    //output(W,H);
    printf("%d\n",bfs(px,py));

  }
}
