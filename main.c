#include <stdio.h>
#include <stdlib.h>
//#include "priorityqueue.h"
#include "search.h"
#include "stats.h"

char *ans = NULL;
int main(int argc,char * argv[])
{
    char temp0[20] ="-j";
    char temp[20]="-h";
    char temp2[20]="-help";
    if(argc==2)
    {
        if(strcmp(temp,argv[1])==1||strcmp(temp2,argv[1])==1)
        {
            printf("\nyou can type .search-cli -g/--graph FILE_PATH -s/--stats STATS_PARAMS\n");
            printf("\nSTATS_PARAMS including: \n\t edges\n\t vertices\n\t freeman\n");
            printf("\nby which you can get some information of the graph\n\n");
			printf("\nyou can also type ./search-cli -g/--graph FILE_PATH -sp/--shortestpath SEARCH_PARAMS -u STARTING_POINT -v TARGET_POINT\n");
			printf("\nby which you can find the shortest path or one normal path\n\n");
        }
        if(strcmp(temp0,argv[1])==1)
        {
            printf("xxxx  xxx                      x \n");
            printf("xxxxxxxxxxxxx                  xx\n");
            printf("  xxxxxxxx                    xxxx\n");
            printf("     xxxxxxxxxxxxxxxxxxxxxxx   x x\n");
            printf("    xx xxx                  xxxxxx\n");
            printf("  xxxxxx                      xx\n");
            printf("xxxxxx                         xxx\n");
            printf("    xx                          xx\n");
            printf("   xx     x             x x      xx\n");
            printf("  xx     xxx             x        xx\n");
            printf(" xx     xxxxx           x x        xx\n");
            printf("xx              xx                  x\n");
            printf("x               xx                   x\n");
            printf("x                                     x\n");
            printf("x               xxxx                  x\n");
            printf("x                                     x\n");
            printf("xxx                                  x\n");
            printf("  xxx                              xx\n");
            printf("   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
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
            printf("%d\n",numberOfEdges(argv[2]));
        }
        if(strcmp(temp4,argv[4]))
        {
            printf("%d\n",numberOfVertices(argv[2]));
        }
        if(strcmp(temp5,argv[4]))
        {
            float ans = freemanNetworkCentrality(argv[2]);
            printf("%f\n" ,ans);
        }
        return 0;
    }
    char * ans;
    int u = atoi(argv[6]), v =atoi(argv[8]);
	//printf("%d  %d",u,v);
	//printf("%d",argc);
    if(argc==9)
    {
		//printf("%s",argv[4]);
		//printf("%s",argv[2]);
        ans = shortestPath(u,v,argv[4],argv[2]);
    }
    puts(ans);
    return 0;
}
