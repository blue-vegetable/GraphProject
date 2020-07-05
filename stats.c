#include <stdio.h>
#include <stdlib.h>
#define Max 500000

int numberOfEdges(char name[])
{
    int count=0;
    FILE* fp1=fopen(name,"r");
    char buf[1024];
    if(fp1==NULL)
    {
        printf("failed to open the file");
        return 1;
    }
    else
    {
        while(fgets(buf,sizeof(buf),fp1)!=NULL)
        {
           count++;
        }
    }
    return count;
}

int numberOfVertices(char name[])
{
    FILE* fp2=fopen(name,"r");
    int visit[500000],a,b,c,count=0;
    if (fp2==NULL) {
        printf("failed to open the file");
        return 1;
    }
    while (!feof(fp2)) {
        fscanf(fp2,"%d%d%d",&a,&b,&c);
        if (visit[a]==0) {
            visit[a]=1;
            count++;
        }
        if (visit[b]==0) {
            visit[b]=1;
            count++;
        }
    }
    return count;
}

typedef struct nodirect_Node{    // a definition of a Node
    int seq;                //its number
    int num;
    struct nodirect_Node * next;  //next node that connected to it
}Noden;

Noden *nodes2[Max];

int searchn(Noden *nodes2[],int x) // check whether a node is created or not
{
    return !(nodes2[x]==NULL);
}


int searchn2(int a,int b)
{
    Noden*  pre =nodes2[a]->next;
    while(pre!=NULL)
    {
        if(pre->seq==b)
            return 1;
        pre = pre->next;
    }
    return 0;
}

static int max2=0;
static int maxseq=0;         //record the index of the greatest node


void  CreateGraph2(char name[20])
{
    FILE* fp1=fopen(name,"r");    //operations about files
    if(fp1==NULL)
    {
        printf("failed to open the file");
        return ;
    }

    Noden *temp = NULL;
    Noden* tempa = NULL;
    Noden *tempb = NULL;

    int value,a,b;
    while(fscanf(fp1,"%d%d%d",&a,&b,&value)!=EOF)  //read until the file ends
    {
        if(a>maxseq)
        {
            maxseq = a;
        }

        if(searchn(nodes2,a)==0)
        {
            nodes2[a] = (Noden*)malloc(sizeof(Noden));
            nodes2[a]->next = NULL;
            nodes2[a]->num = 0;
        }
        if(searchn(nodes2,b)==0)
        {
            nodes2[b] = (Noden*)malloc(sizeof(Noden));
            nodes2[b]->next = NULL;
            nodes2[b]->num = 0;
        }

        if(searchn2(a,b)==1)
        {
            continue;
        }

        tempb = (Noden*)malloc(sizeof(Noden));
        tempb->seq = b;
        tempb->next = NULL;

        temp = nodes2[a];
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = tempb;
        nodes2[a]->num+=1;

        tempa = (Noden*)malloc(sizeof(Noden));
        tempa->seq = a;
        tempa->next = NULL;

        temp = nodes2[b];
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = tempa;
        nodes2[b]->num+=1;
    }

    for(int i=0;i<=maxseq;i++)
    {
        if(nodes2[i]!=NULL)
        {
            if(max2<nodes2[i]->num)
            {
                max2 = nodes2[i]->num;
            }
        }
    }
}

float freemanNetworkCentrality(char name[])
{
    CreateGraph2(name);
    float ans=0;
    int count=0;
    for(int i=0;i<=maxseq;i++)
    {
        if(nodes2[i]==NULL)
        {
            continue;
        }
        ans += (max2-nodes2[i]->num);
        count++;
    }
    return ans/((count-1)*(count-2));
}


