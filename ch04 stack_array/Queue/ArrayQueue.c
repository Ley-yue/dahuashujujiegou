#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef int status;
#define ok 1
#define error 0
#define QueueSize 10
typedef struct QueueNode{
    Elemtype data[QueueSize];
    int front;
    int rear;
}sqQueue;

void InitQueue(sqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
}

void ClearQueue(sqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
}

int QueueEmpty(sqQueue Q)
{
    if(Q.front==Q.rear)
        return ok;
    return error;
}

int QueueLength(sqQueue Q)
{
    return (Q.rear-Q.front+QueueSize)%QueueSize;
}

Elemtype GetHead(sqQueue Q)
{
    if(Q.front==Q.rear)
        return error;
    return Q.data[Q.front];
}

int EnQueue(sqQueue *Q,Elemtype e)
{
    if((Q->rear+1)%QueueSize==Q->front)
        return error;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%QueueSize;  //循环队列，不能忘记循环
    return ok;
}

Elemtype DeQueue(sqQueue *Q)
{
    if(Q->front==Q->rear)
        return error;
    int e;
    e=Q->data[Q->front];
    Q->data[Q->front]=0;
    Q->front=(Q->front+1)%QueueSize;    //头指针后移
    return e;
}

void print(sqQueue Q)
{
    int i=Q.front;
    while((Q.front+i)!=Q.rear)
    {
        printf("%d \n",Q.data[i]);
        i=(i+1)%QueueSize;
    }
}

int main()
{
    int i=0,n;
    int l;
    sqQueue Q;
    InitQueue(&Q);
    while(i<9)
    {
        EnQueue(&Q,i+1);
        i++;
    }
    print(Q);
    l=QueueLength(Q);
    printf("length:%d \n",l);
    for(i=0;i<5;i++)
        n=DeQueue(&Q);
    printf("---------------\n");
    print(Q);
    int h=GetHead(Q);
    printf("head:%d \n",h);

    l=QueueLength(Q);
    printf("length:%d \n",l);
    printf("---------------\n");

    ClearQueue(&Q);
    printf("is empty? %d \n",QueueEmpty(Q));
    
    system("pause");
    return 0;
}