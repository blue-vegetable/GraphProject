#include <stdio.h>
#include <stdlib.h>
//#include "priorityqueue.h"
#include "search.h"
#include "stats.h"

Node* nodes[Max];
int fuck[Max]={0};

int main()
{

    char name[20] = "test.txt";
    CreateGraph(name,nodes);
    printf("Create Graph succeed");
    int count;
    int u=2,v=21119;
    PriorityQueue a = NULL;
    count = Dijkstra(u,v,a,nodes,fuck);
    int i;
    for(i=count-1;i>=0;i--)
    {
       printf(" %d ->",fuck[i]);
    }
    printf("%d",v);


}
