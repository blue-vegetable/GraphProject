typedef struct Node22{
    int a,b,c;
}Box;

struct BinaryHeap {
    unsigned int capacity;
    unsigned int size;
    Box *heap;    // struct of  a binary-heap
};

typedef struct BinaryHeap * PriorityQueue;

int cmp(Box a,Box b);

PriorityQueue Init(unsigned int capacity);

int Insert(PriorityQueue pPqueue, Box x);

Box Dequeue(PriorityQueue pPQueue);

