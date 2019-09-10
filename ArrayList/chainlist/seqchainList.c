#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef int Elemtype;
typedef int status;
#define ok 1
#define error 0
typedef struct{
    Elemtype data;/* data */
    int cur;
}Component,seqchainList[MAXSIZE];

//创建静态链表
status InitStaticList(seqchainList space)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++)
    {
        space[i].cur=i+1;
        space[MAXSIZE-1].cur=0;
    }
    return 1;
}

//手动分配空闲节点
int malloc_SLL(seqchainList space)
{
    int i;
    i=space[0].cur; //读取空闲节点位置
    if(space[i].cur)    //判断是否空闲
        space[0].cur=space[i].cur;  //更新头结点信息（空闲位置）
    return i;
}

void free_SLL(seqchainList space,int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}

int ListLength(seqchainList L)
{
    int j=0;
    int k=L[MAXSIZE-1].cur;
    while(k)
    {
        k=L[k].cur;
        j++;
    }
    return j;
}

//插入节点
status ListInsert(seqchainList space,Elemtype e,int k)
{
    int i,j,l;
    i=MAXSIZE-1;
    if(k<1||k>ListLength(space)+1)
        return error;
    j=malloc_SLL(space);    //获取第一个空闲节点位置
    if(j)
    {
        space[j].data=e;
        for(l=1;l<=k-1;l++) //找到第k个节点的前一个节点
            i=space[i].cur; //从最后一个开始（尾部指向第一个非空闲节点）
        space[j].cur=space[i].cur;  //插队，新节点指向被插节点的后一个
        space[i].cur=j; //被插节点指向新节点
        return ok;
    }
    return error;
}

status ListDelete(seqchainList L,int i)
{
    int j,k,l;
    if(i<1||i>ListLength(L))
        return error;
    k=MAXSIZE-1;
    for(l=1;l<i-1;l++)
        k=L[k].cur;
    j=L[k].cur;
    L[k].cur=L[j].cur;
    free_SLL(L,j);
    return ok;
}

void PrintList(seqchainList L)
{
    int i,j;
    i=ListLength(L);
    for(j=0;j<i;j++)
    {
        printf("%d:%d \n",j+1,L[j+1].data);
    }
}

int main()
{
    int i=0;
    seqchainList L;
    InitStaticList(L);
    for(i=0;i<10;i++)
        ListInsert(L,i,i+1);
    PrintList(L);
    ListDelete(L,5);
    PrintList(L);
    system("pause");
    return 0;
}