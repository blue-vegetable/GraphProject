#include <stdio.h>
#include <stdlib.h>
//#include "priorityqueue.h"
#include "search.h"
#include "stats.h"

int main()
{
    char name[20] = "test.txt";
  //  CreateGraph(name);
    printf("Create Graph succeed");

    int u=2,v=22446;
    PriorityQueue a = NULL;
    Dijkstra(u,v,a);

    int i;
    for(i=count-1;i>=0;i--)
    {
        printf(" %d ->",ans[i]);
    }

    printf("%d",v);

}
