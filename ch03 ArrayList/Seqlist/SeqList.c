#include "./SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define false 0
#define true 1
typedef int ElemType;

#define Initsize 10    //表初始长度
typedef struct {
    ElemType *data; //动态开辟空间
    int Maxsize,length;
}SqList;

int main()
{
    SqList L,B;
    InitList(&L);
    InitList(&B);
    for(int i=1;i<=10;i++)
        InsertElem(&L,i,i);
    for(int i=1;i<=15;i++)
        InsertElem(&B,i,i);
    PrintList(&L);
    DeleteElem(&L,5);
    printf("*****************\n");
    unionList(&L,&B);
    PrintList(&L);
    system("pause");
    return 0;
}

int InitList(SqList *L)
{
    L->data=(ElemType*)malloc(sizeof(ElemType)*Initsize);
    if(!L->data)
    {
        printf("malloc failed.\n");
        exit(1);
    }
    L->length=0;
}
int GetLength(SqList *L)
{
    return L->length;
}
int isEmpty(SqList *L)
{
    if(L->length==0)
        return true;
    else return false;
}
//将num插入到第i个位置
int InsertElem(SqList *L,int i,ElemType num)
{
    int j;
    if(i<1||i>L->length+1)
    return false;
    if(i>=L->Maxsize)
    return false;
    for(j=L->length;j>=i;j--)
        L->data[j]=L->data[j-1];

    L->data[i-1]=num;
    L->length++;
    return true;
}
//删除第i个位置的数
int DeleteElem(SqList *L,int i)
{
    int j;
    if(i<1||i>L->length)
    return false;
    for(j=i;j<L->length;j++)
        L->data[j-1]=L->data[j];    //length是长度不是数组下标，length-1才是下标；而且移到data[j+1]中，最后一个数会越界
    
    L->data[L->length-1]=0;
    L->length--;
    return true;
}
void GetElem(SqList *L,int i,ElemType *e)
{
    if(i>L->length)
    printf("length out.\n");

    *e=L->data[i-1];
}
int LocateElem(SqList *L,ElemType e)
{
    int i;
    for(i=0;i<L->length;i++)
        if(L->data[i]==e)
            return ++i;
    return false;
}
void PrintList(SqList *L)
{
    int i;
    for(i=0;i<L->length;i++)
        printf("linelist %d:%d \n",i+1,L->data[i]);
    
}
void DestoryList(SqList *L)
{
    if(L!=NULL)
    free(L);
}

//衍生操作
int unionList(SqList *A,SqList *B)
{
    int la,lb;
    ElemType e;
    la=GetLength(A);
    lb=GetLength(B);
    for(int i=1;i<=lb;i++)
    {
        GetElem(B,i,&e);
        if(LocateElem(A,e)==false)
        InsertElem(A,++la,e);
    }
    return true;
}