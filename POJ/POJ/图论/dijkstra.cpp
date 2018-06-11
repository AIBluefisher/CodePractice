#include <cstdio>

#define MAXV 110

typedef struct EdgeNode
{
  int to;
  int weight;
  EdgeNode* nextEdge;
}Edge;
typedef struct HeadNode
{
  EdgeNode* firstEdge;
}Head;
typedef struct
{
  Head headList[MAXV];
}Graph;

void dijkstra()
{

}
