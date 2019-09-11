#include<stdio.h>
#include<stdlib.h>

#define error 0
#define ok 1
#define MAXSIZE 20
typedef int status;
typedef int Elemtype;
typedef struct stack
{
    Elemtype data[MAXSIZE];/* data */
    int top;
}Sqstack;

status InitStack(Sqstack *S)
{
    S->top=-1;
    return ok;
}

status ClearStack(Sqstack S)
{
    S.top=-1;
    return ok;
}

Elemtype GetTop(Sqstack S)
{
    return S.data[S.top];
}

int GetLength(Sqstack S)
{
    if(S.top==-1)
    return error;
    return S.top++;
}

int StackEmpty(Sqstack S)
{
    if(S.top==-1)
    return 1;
    else return 0;
}

status push(Sqstack *S,Elemtype e)
{
    if(S->top>MAXSIZE-1)
    return error;
    S->top++;
    S->data[S->top]=e;
    return ok;
}

Elemtype pop(Sqstack *S)
{
    if(S->top>MAXSIZE-1)
    return error;
    Elemtype e=S->data[S->top];
    S->top--;
    return e;
}

void PrintStack(Sqstack S)
{
    for(int i=0;i<=S.top;i++)
    {
        printf("%d \n",S.data[i]);
    }
}

int main()
{
    Sqstack S;
    InitStack(&S);
    for(int i=0;i<10;i++)
    {
        push(&S,i);
    }
    PrintStack(S);
    printf("ouput the last number:%d \n",pop(&S));
    PrintStack(S);
    system("pause");
    return 0;
}