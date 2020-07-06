#include <stdio.h>
#include <stdlib.h>
//#include "priorityqueue.h"
#include "search.h"
#include "stats.h"

char *ans = NULL;
int main(int argc,char * argv[])
{
    char temp[20]="-h";
    char temp2[20]="-help";
    if(argc==2)
    {
        if(strcmp(temp,argv[1])==0||strcmp(temp2,argv[1])==0)
        {
            printf(".search-cli -g/--graph FILE_PATH -s/--stats STATS_PARAMS\n");
            printf("STATS_PARAMS including: \n\t edges\n\t vertices\n\t freeman\n");
            printf("by which you can get some information of the graph\n");
            printf("./search-cli -g/--graph FILE_PATH -sp/--shortestpath SEARCH_PARAMS -u STARTING_POINT -v TARGET_POINT");
        }
        return 0;
    }

    char temp3[20]="edges";
    char temp4[20]="vertices";
    char temp5[20]="freeman";
    if(argc==5)
    {
        if(strcmp(temp3,argv[4]))
        {
            printf("The number of edges are %d",numberOfEdges(argv[2]));
        }
        if(strcmp(temp4,argv[4]))
        {
            printf("The number of vertices are %d",numberOfVertices(argv[2]));
        }
        if(strcmp(temp5,argv[4]))
        {
            float ans = freemanNetworkCentrality(argv[2]);
            printf("Freeman : %f\n" ,ans);
        }
        return 0;
    }
    char temp7[20] = "DFS";
    char temp8[20] = "BFS";
    char temp9[20] = "Dijkstra";
    char * ans;
    int u = argv[6][0], v = argv[8][0];
    if(argc==8)
    {
        ans = shortestPath(u,v,argv[4],argv[2]);
    }
    puts(ans);
    return 0;
}
