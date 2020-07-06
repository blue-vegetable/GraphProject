#include <stdio.h>
#include <stdlib.h>
//#include "priorityqueue.h"
#include "search.h"
#include "stats.h"

Node* nodes[Max];
int hai[Max]={0};

int main()
{
    char name[20] = "test.txt";
    CreateGraph(name,nodes);
    printf("Create Graph succeed");
    int count;
    int u=2,v=21122;
    PriorityQueue a = NULL;
    count = BFS(u,v,nodes,hai);
    int i;
    for(i=count-1;i>=0;i--)
    {
       printf(" %d ->",hai[i]);
    }

}
