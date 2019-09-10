/*
双向循环列表
*/
#include<stdio.h>
#include<stdlib.h>

#define ok 1
#define error 0
#define status int
#define ElemType int
typedef struct Node{
    Node *pHead;
    ElemType data;
    Node *next;
}Node,*CirLinkList;

int ListLength(CirLinkList L)
{
    int i=0;
    Node *p;
    p=L->next;
    if(p==NULL)
    return error;
    while(p)
    {
        p=p->next;
        i++;
    }
    return i;
}

ElemType GetElem(CirLinkList L,int i)
{
    int j=1;
    ElemType k;
    Node *p;
    p=L->next;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
    return error;
    k=p->data;
    return k;
}

int LocalElem(CirLinkList L,ElemType e)
{
    int j=1,k=e;
    Node *p;
    p=L->next;
    while(p&&(k!=p->data))
    {
        p=p->next;
        j++;
    }
    if(!p)
    return error;
    return k;
}

status InitList(CirLinkList *L)
{
    *L=(Node*)malloc(sizeof(Node*));
    (*L)->next=NULL;
    if(!L)
        return error;
    return ok;
}

status CreatList(CirLinkList *L,int *e,int length)
{
    int i=0;
    Node *p,*q;
    *L=(Node*)malloc(sizeof(Node*));
    (*L)->next=NULL;
    if(!L)
    return error;
    while(i<length)
    {
        p=(*L)->next;
        q=(Node*)malloc(sizeof(Node*));
        q->data=e[i];
        q->next=p;
        (*L)->next=q;
    }
    return ok;
}

status InsertList(CirLinkList *L,int i,ElemType e)
{
    int j=0;
    Node *p,*q;
    p=(*L)->next;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    q=(Node*)malloc(sizeof(Node));
    
}
