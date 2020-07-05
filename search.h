#define Max 500000
#include "priorityqueue.h"

typedef struct Node{    // a definition of a Node
    int seq;                //its number
    int value;           // its value
    struct Node * next;  //next node that connected to it
    struct Node * down;

}Node;

Node *nodes[Max];
int ans[Max]={0};
int parent[Max]={0};
int visit[Max]={0};
int length[Max]={0};
int count;


void BFS(int u,int v);
void  CreateGraph(char name[20]);
void Dijkstra(int u,int v,PriorityQueue a);
void DFS(int u,int v);
