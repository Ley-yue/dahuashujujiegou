#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
#define MAXSIZE 20
typedef int status;
typedef int Elemtype;
typedef struct{
    Elemtype data[MAXSIZE];
    int top1;
    int top2;
}DoubleStack;

void InitDoubleStack(DoubleStack *S)
{
    S->top1=-1;
    S->top2=MAXSIZE;
}

void ClearStack(DoubleStack *S)
{
    S->top1=-1;
    S->top2=MAXSIZE;
}

status GetTop(DoubleStack S,Elemtype *e1,Elemtype *e2)
{
    if(S.top1==-1||S.top2==MAXSIZE-1)
        return error;
    *e1=S.data[S.top1];
    *e2=S.data[S.top2];
    return ok;
}

int GetLength(DoubleStack S)
{
    return S.top1+1+MAXSIZE-S.top2; //头减尾
}

status StackEmpty(DoubleStack S)
{
    if(S.top1==-1&&S.top2==MAXSIZE)
        return ok;
    else return error;
}

status push(DoubleStack *S,Elemtype e,int stacknumber)
{
    if(S->top1+1==S->top2)
    {
        return error;
    }
    if(stacknumber==1)
        S->data[++S->top1]=e;
    if(stacknumber==2)
        S->data[--S->top2]=e;
    else return error;
    return ok;
}

Elemtype pop(DoubleStack *S,int stacknumber)
{
    if(stacknumber==1)
    {
        if(S->top1==-1)
            return error;
        return S->data[S->top1--];
    }
    else if(stacknumber==2)
    {
        if(S->top2==MAXSIZE)
            return error;
        return S->data[S->top2++];
    }
}

status PrintStack(DoubleStack S)
{
    if(StackEmpty(S)==1)
    return error;
    for(int i=0;i<=S.top1;i++)
        printf("Stack1:%d \n",S.data[i]);
    printf("----------------\n");
    for(int j=S.top2;j<MAXSIZE;j++)
        printf("Stack2:%d \n",S.data[j]);

    return ok;
}

int main()
{
    int j;
    DoubleStack S;
    int e;
    InitDoubleStack(&S);
    for(j=1;j<=5;j++)
        push(&S,j,1);
    for(j=MAXSIZE;j>=MAXSIZE-5;j--)
        push(&S,j,2);

    PrintStack(S);
    system("pause");
    return 0;
}