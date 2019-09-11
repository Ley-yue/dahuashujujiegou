#include<stdio.h>
#include<stdlib.h>
#define error 0
#define ok 1
typedef int Elemtype;
typedef int status;
typedef struct StackNode{
    Elemtype data;
    StackNode *next;
}StackNode,*ChainStackPrt;
typedef struct{
    ChainStackPrt top;
    int count;
}LinkStack;

status InitStack(LinkStack *S)
{
    S->top=(ChainStackPrt)malloc(sizeof(ChainStackPrt));
    if(!S->top)
        return error;
    S->top=NULL;
    S->count=0;
    return ok;
}

void ClearStack(LinkStack *S)
{
    ChainStackPrt q,p;
    p=S->top;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    S->count=0;
}
int GetLength(LinkStack S)
{
    return S.count;
}

int StackEmpty(LinkStack S)
{
    if(S.count==0)
        return 1;
    else return 0;
}

Elemtype GetTop(LinkStack S) 
{
    if(S.count)
        printf("get top error.\n");
    return S.top->data;
}

void push(LinkStack *S,Elemtype e)
{
    ChainStackPrt p=(ChainStackPrt)malloc(sizeof(ChainStackPrt));
    if(!p)
        printf("push error.\n");
    p->data=e;
    p->next=S->top;
    S->top=p;
    S->count++;

}

Elemtype pop(LinkStack *S)
{
    Elemtype e;
    ChainStackPrt p=(ChainStackPrt)malloc(sizeof(ChainStackPrt));
    if(!p)
        printf("pop error.\n");
    p=S->top;
    e=p->data;
    S->top=S->top->next;
    free(p);
    S->count--;
    return e;
}

void PrintStack(LinkStack S)
{
    int i=0;
    ChainStackPrt p=(ChainStackPrt)malloc(sizeof(ChainStackPrt));
    p=S.top;
    while(i<S.count&&p)
    {
        i++;
        printf("%d:%d \n",i,p->data);
        p=p->next;
    }
}

int main()
{
    int i;
    LinkStack S;
    InitStack(&S);
    for(i=0;i<10;i++)
        push(&S,i*i);
    PrintStack(S);

    printf("%d \n",GetLength(S));
    printf("%d \n",pop(&S));
    ClearStack(&S);
    printf("%d \n",StackEmpty(S));
    system("pause");
    return 0;
}