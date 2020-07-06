#define Max 500000
#include "priorityqueue.h"

typedef struct Node{    // a definition of a Node
    int seq;                //its number
    int value;           // its value
    struct Node * next;  //next node that connected to it
    struct Node * down;
}Node;

typedef struct
{
    int seq;
    int dis;
    int par;
    Node* now;
}Box2;

int strcmp(char a[],char b[]);
void  CreateGraph(char name[20],Node* nodes[]);
int  Dijkstra(int u,int v,PriorityQueue a,Node * nodes[],int ans[]);
int DFS(int u,int v, Node* nodes[],int ans[]);
int BFS(int u,int v,Node* nodes[],int ans[]);
char * shortestPath(int u, int v, char algorithm[], char name[]);

