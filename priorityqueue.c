#include<stdio.h>
#include<stdlib.h>

typedef struct Node2{
    int a,b,c;
}Box;

int cmp(Box a,Box b)
{
    if(a.b>b.b)
        return 1;
    else
        return 0;
}

struct BinaryHeap {
    unsigned int capacity;
    unsigned int size;
    Box *heap;    // struct of  a binary-heap
};

typedef struct BinaryHeap * PriorityQueue;

PriorityQueue Init(unsigned int capacity)
{
    PriorityQueue pPQueue = (PriorityQueue)malloc(sizeof(struct BinaryHeap));
    pPQueue->heap = (Box *)malloc(sizeof(Box)*capacity);

    pPQueue->capacity = capacity;
    pPQueue->size = 0;
    pPQueue->heap[0].a = -1;
    pPQueue->heap[0].b = -1;
    return pPQueue;
}

int Insert(PriorityQueue pPqueue, Box x)
{
    if(pPqueue->size == pPqueue->capacity-1)
    {
        return 0;
    }
    unsigned int CurPos = ++pPqueue->size;
    for(;cmp(pPqueue->heap[CurPos/2], x);CurPos/=2)
    {
        pPqueue->heap[CurPos] = pPqueue->heap[CurPos/2];

    }
    pPqueue->heap[CurPos] = x;
    return 1;
}

Box Dequeue(PriorityQueue pPQueue)
{
    Box e;
    e.a=0;e.b =0;
    if(pPQueue->size == 0)
        return e;
    Box root = pPQueue->heap[1];
    Box LastElement = pPQueue->heap[pPQueue->size--];
    unsigned int Curpos =1;
    unsigned int child = Curpos*2;
    while(child<=pPQueue->size)
    {
        if(child != pPQueue->size && cmp(pPQueue->heap[child], pPQueue->heap[child+1]))
        {
            child+=1;
        }
        if(cmp(LastElement,pPQueue->heap[child]))
        {
            pPQueue->heap[Curpos]=pPQueue->heap[child];
            Curpos = child;
            child = Curpos * 2;
        }
        else
            break;
     }
        pPQueue->heap[Curpos] = LastElement;
        return root;
}

