#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef int status;
#define ok 1
#define error 0
typedef struct QueueNode{
    Elemtype data;
    QueueNode *next;
}QueueNode,*QueuePtr;
typedef struct LinkQueue{
    QueuePtr front,rear;
}LinkQueue;

void InitQueue(LinkQueue *Q)
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(LinkQueue));
    if(!Q)
        printf("Init error.\n");
    Q->front->next=NULL;    //头尾不存储数据
}

void ClearQueue(LinkQueue *Q)
{
    QueuePtr p,q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
}

int GetLength(LinkQueue Q)
{
    int i=0;
    QueuePtr p;
    p=Q.front->next;
    while(p!=Q.rear)
    {
        p=p->next;
        i++;
    }
    return i;
}

Elemtype GetHead(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return error;
    return Q.front->next->data;
}

int QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return ok;
    else return error;
}

void DestroyQueue(LinkQueue *Q)
{
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
}

status EnQueue(LinkQueue *Q,Elemtype e)
{
    QueuePtr q=(QueueNode*)malloc(sizeof(QueueNode));
    QueuePtr p;
    if(!q)
        return error;
    q->data=e;
    q->next=NULL;
    Q->rear->next=q;
    Q->rear=q;
    return ok;
}

Elemtype DeQueue(LinkQueue *Q)
{
    int e;
    QueuePtr p;
    if(Q->front==Q->rear)
        return error;
    p=Q->front->next;
    e=p->data;
    Q->front->next=p->next;
    if(p==Q->rear)
        Q->rear=Q->front;
    free(p);
    return e;
}

void PrintQueue(LinkQueue Q)
{
    int i;
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}

int main()
{
    int i;
    LinkQueue Q;
    InitQueue(&Q);
    for(i=0;i<10;i++)
    {
        EnQueue(&Q,i+1);
    }
    PrintQueue(Q);
    printf("head:%d \n",GetHead(Q));
    printf("length:%d \n",GetLength(Q));
    printf("----------------\n");
    for(i=0;i<4;i++)
        DeQueue(&Q);
    PrintQueue(Q);
    printf("head:%d \n",GetHead(Q));
    printf("length:%d \n",GetLength(Q));
    printf("----------------\n");
    ClearQueue(&Q);
    printf("is that empty?%d \n",QueueEmpty(Q));
    DestroyQueue(&Q);
    printf("destroy this queue,q.front=%u q.rear=%u\n",Q.front, Q.rear);
    system("pause");
    return 0;
}