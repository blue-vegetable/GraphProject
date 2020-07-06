#include <stdio.h>
#include <stdlib.h>
#include "priorityqueue.h"
#define Max 500000

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

Node* nodes[Max];
int visit[Max]={0};
int parent[Max]={0};
int length[Max]={0};
char FinalAns[Max];
Node* stack[Max];


char * strcat(char * dest, const char * src)
{
        char *tmp = dest;
        while (*dest)
        {
            dest++;
        }
        while ((*dest++ = *src++) != '\0');
        return tmp;
} //该函数来自stting.h库文件中的一部分

int search(Node *nodes[],int x) // check whether a node is created or not
{
    return !(nodes[x]==NULL);
}

int strcmp(char a[],char b[])
{
    for(int i=0;a[i]==b[i];i++)
    {
        if(a[i]=='\0'&&b[i]=='\0')
            return 1;
    }
    return 0;
}

void disp(Node* nodes[],int n)
{
    Node* temp=NULL ;
    for(int i=0;i<=n;i++)
    {
        if(nodes[i]!=NULL)
        {
            printf("%d:",nodes[i]->seq);
            temp = nodes[i]->next;
            while(temp!=NULL)
            {
                printf(" %d value:%d  ",temp->seq,temp->value);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

void  CreateGraph(char name[20],Node* nodes[])
{
    FILE* fp1=fopen(name,"r");    //operations about files
    if(fp1==NULL)
    {
        printf("failed to open the file");
        return ;
    }

    Node *temp = NULL;
    Node *tempb = NULL;
    int maxseq=0;         //record the index of the greatest node

    int value,a1,b;
    while(fscanf(fp1,"%d%d%d",&a1,&b,&value)!=EOF)  //read until the file ends
    {
        if(a1>maxseq)
        {
            maxseq = a1;
        }
        if(search(nodes,a1)==0)
        {
            nodes[a1] = (Node*)malloc(sizeof(Node));
            nodes[a1]->seq = a1;
            nodes[a1]->next = NULL;
            nodes[a1]->down = NULL;
            nodes[a1]->value = 0;
        }

        tempb = (Node*)malloc(sizeof(Node));
        tempb->value = value;
        tempb->seq = b;
        tempb->next = NULL;

        temp = nodes[a1];
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = tempb;

        if(search(nodes,b)==0)
        {
            nodes[b] = (Node*)malloc(sizeof(Node));
            nodes[b]->next=NULL;
            nodes[b]->seq = b;
        }

    }

    Node *head = (Node*)malloc(sizeof(Node));
    Node *pre =head;
    for(int i=0;i<=maxseq;i++)
    {
        if(nodes[i]!=NULL)
        {
            pre->down = nodes[i];
            pre = nodes[i];
        }
    }
  	//disp(nodes,maxseq);
}



int  Dijkstra(int u,int v,PriorityQueue a,Node * nodes[],int ans[])
{
    int count=0;
    a=Init(Max);
    Node * pre = nodes[u];

    Box e;

    e.a = pre->seq;
    e.b = pre->value;
    e.c = -1;
    parent[e.a] = e.c;

    Insert(a,e);

    while(1)
    {
        while(1) {
            e = Dequeue(a);
            if(visit[e.a]==1||length[e.a]<e.b&&length[e.a]!=0)
                continue;
            else
            {
                visit[e.a] = 1;
                length[e.a] = e.b;
                parent[e.a] = e.c;
                break;
            }
        }

        if(e.a==v)
        {
            visit[e.a] = e.c;
            break;
        }
        if(nodes[e.a]==NULL)
        {
            continue;
        }

        pre = nodes[e.a]->next;

        Box e1;

        while(pre!=NULL)
        {
            e1.a = pre->seq;
            e1.b = pre->value+e.b;
            e1.c = e.a;

            Insert(a,e1);
            pre = pre->next;
        }
    }

    int m = v;
    ans[count++] = v;
    while(parent[m]!=-1)
    {
        ans[count++] = parent[m];
        m = parent[m];
    }
    return count;

}

int DFS(int u,int v, Node* nodes[],int ans[])
{

    int top = 0;
    int flag = 0;
    stack[++top] = nodes[u];
    visit[u] = 1;
    Node *pre;
    while(top!=0)
    {
        pre = stack[top];
        if(pre->seq == v)
        {
            break;
        }
        if(flag==1)
        {
            pre = nodes[pre->seq]->next;
        }
        if(pre==NULL)
        {
            top--;
            flag =1;
            continue;
        }
        if(flag!=1)
        {
            pre = nodes[pre->seq]->next;
        }
        flag = 0;
        while(pre!=NULL&&visit[pre->seq]==1)
        {
            pre = pre->next;
        }
        if(pre==NULL)
        {
            top--;
            flag=1;
            continue;
        }

        stack[++top] =  pre;
        visit[pre->seq] = 1;
    }

    for(int i=1;i<=top;i++)
    {
        ans[i-1] = stack[i]->seq;
    }
    if(top==0)
        puts("stack empty");
    return top;
}

Box2 queue[Max];
int BFS(int u,int v,Node *nodes[],int ans[])
{
    if(nodes[0]==NULL)
    {
        nodes[0]=(Node*)malloc(sizeof(Node));
        nodes[0]->seq  = 0;
        nodes[0]->next=NULL;
    }
    int front=0,tail=0;
    int parent2;

    Box2 e;
    e.seq = u;
    length[u] = 0;
    parent[u] = -1;
    visit[u] = 1;

    queue[tail++] = e;
    Node * pre;

    while(front<=tail)
    {
        e = queue[front];       //dequeue
        front++;
        visit[e.seq] = 0;

        pre = nodes[e.seq]->next;
        parent2 = e.seq;
        while(pre != NULL)
        {
            if(length[pre->seq]>length[parent2]+pre->value||length[pre->seq]==0)
            {
                length[pre->seq] = length[parent2]+pre->value;
                parent[pre->seq] = parent2;
                if(!visit[pre->seq])
                {
                    e.seq = pre->seq;
                    queue[tail++] = e;
                    visit[e.seq] = 1;
                }
            }
            pre = pre->next;
        }

    }
        int m  = v;

        int count =0;
        while(m!=u)
        {
            ans[count++] = m;
            m = parent[m];
        }
        ans[count++] = u;
        return count;
}


char * shortestPath(int u, int v, char algorithm[], char name[])
{
    int count = 0;
    int flag = 0;
    int ans[Max]={0};
    char tempn[100];
    PriorityQueue a = NULL;
    CreateGraph(name,nodes);
    char temp[10] = "DFS";
    if (strcmp(algorithm, temp) == 1)
    {
        count = DFS(u,v,nodes,ans);
        flag = 1;
    }
    char temp2[20] ="BFS";
    if (strcmp(algorithm, temp2) == 1)
    {
        count = BFS(u,v,nodes,ans);
    }
    char temp3[20] = "Dijkstra";
    if (strcmp(algorithm,temp3) == 1)
    {
        count = Dijkstra(u,v,a,nodes,ans);
    }

    if(flag==0)
    {
        for(int i=count-1;i>=0;i--)
        {
            if(i!=0)
            {
                sprintf(tempn,"%d-> ",ans[i]);
                strcat(FinalAns,tempn);
            }
            else
            {
                sprintf(tempn,"%d",ans[i]);
                strcat(FinalAns,tempn);
            }
        }
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            if(i!=count-1)
            {
                sprintf(tempn,"%d-> ",ans[i]);
                strcat(FinalAns,tempn);
            }
            else
            {
                sprintf(tempn,"%d",ans[i]);
                strcat(FinalAns,tempn);
            }
        }
    }
    return FinalAns;
}






