#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef int status;
#define error 0
#define ok 1

typedef struct Node{    /*链表的每一个节点 */
    Elemtype data;
    struct Node *next;
    int flag;
}Node;
typedef Node *ChainList; /*链表 */

status InitList(ChainList *L)   /*创建空表 */
{
    *L=(ChainList)malloc(sizeof(ChainList));
    if(!L)
        return error;
    (*L)->next=NULL;
    return ok;
}

status CreateHeadList(ChainList *L,int length)
{
    int i=0;
    Node *p,*q;
    *L=(ChainList)malloc(sizeof(ChainList));
    q=*L;
    (*L)->next=NULL;
    while(i<length)
    {
        i++;
        p=(Node*)malloc(sizeof(Node));
        p->data=i;
        /*头插法 */
        p->next=(*L)->next;
        (*L)->next=p;
    }
    if(!L)
    return error;
    return ok;
}

//尾插法
void CreateLeftList(ChainList *L,int length)
{
    int i=0;
    Node *p,*q;
    (*L)=(ChainList)malloc(sizeof(ChainList));
    (*L)->next=NULL;
    q=(*L);
    while(i<length)
    {
        i++;
        p=(Node *)malloc(sizeof(Node));
        p->data=i*i-3*i+3;
        q->next=p;
        q=p;
    }
    q->next=NULL;
}

status ClearList(ChainList L)
{
    Node *p,*q;
    p=L->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    if(!p)
        return error;
    return ok;
}

status GetElem(ChainList L,Elemtype *e,int i)
{
    Node *p;    /*链表的单节点操作 */
    int j=1;
    p=L->next;
    while(p&&j<i)   /*遍历第i个之前的节点 */
    {
        p=p->next;
        j++;
    }
    if(!p||j>i) /*为空或者超出数组长度 */
        return error;
    *e=p->data; /*把值存入指针e中 */
    return ok;
}

int LocateElem(ChainList L,Elemtype e)
{
    int i=1;
    Node *p;
    p=L->next;
    while(p&&(p->data!=e))
    {
        p=p->next;
        i++;
    }
    if(!p)
    return -1;
    return i;
}

int GetLength(ChainList L)
{
    int i=0;
    ChainList p;
    p=L->next;  /*有一个头结点始终为空，不计入长度 */
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

status InsertElem(ChainList *L,Elemtype e,int i)
{
    int j=1;
    Node *p,*s;
    p=*L;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
        return error;
    s=(Node*)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return ok;
}

status DeleteElem(ChainList *L,Elemtype *e,int i)
{
    Node *p,*q;
    int j=1;
    p=*L;
    while(p->next&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i)
        return error;
    q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
    return ok;
}

void PrintList(ChainList L)
{
    int i=0,e;
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p=L->next;
    while(p)   /*条件为p，并非p->next，因为判断时会多前进一格 */
    {
        e=p->data;
        printf("%d--->%d\n",i+1,e);
        p=p->next;
        i++;
    }
    printf("-------------------------------\n");
}

int main()
{
    int e;
    ChainList L;
    CreateLeftList(&L,10);
    //InitList(&L);
    InsertElem(&L,45,1);
    PrintList(L);
    printf("the value is at the %dth.\n",LocateElem(L,31));
    DeleteElem(&L,&e,8);
    printf("Value %d was deleted.\n",e);
    PrintList(L);
    printf("the value is at the %dth.\n",LocateElem(L,31));
    system("pause");
    return 0;
}