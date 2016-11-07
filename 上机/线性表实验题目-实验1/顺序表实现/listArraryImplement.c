#include<stdlib.h>
#include<stdio.h>
#include"listArraryImplement.h"

/************************************
        Date Struct Course Work
Chengdu University of Information Technology

    Author:Long Zhang
    Student ID:2015051152
    E-mail: kanchisme@gmail.com
    Blog:  http://lucky1965.xyz

    Compile Envirement:
                    Ubuntu 16.04 LTS
                    g++ 5.4
                    VS Code 
************************************/

Status InitList(List *L)
{
    L->len = 0;
    L->listsize = 100;
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
}

Status DestroyList(List *L)
{
    L->len = 0;
    L->listsize = 0;
    free(L->elem);
}

Status ListLength(List L)
{
    return L.len;
}
Status GetElem(List L,int i,ElemType *e)
{
    if( i >= 1 && i<=ListLength(L))
    {
        *e = L.elem[i-1];
        return OK;
    }
    return ERROR;
}
Status LocateElem(List L,ElemType e,ElemType (*f)(ElemType a,ElemType b))
{
    for(int i=0;i<L.len;i++)
    {
        //printf("L.elem[%d]=%d,e=%d,f()=%d\n",i,L.elem[i] ,e , f(L.elem[i],e));
        if(L.elem[i] == f(L.elem[i],e))
        {
            return (i+1);
        }
    }
    //printf("RETURN ERROR\n");
    return ERROR;
}

ElemType equal(ElemType a,ElemType b)
{
    if(a == b)
    {
        return a;
    }
    return 9999;
}

Status ListInsert(List *L,int i,ElemType e)
{
    if( i < 1 || i > ListLength(*L) + 1 )
    {
        return ERROR;
    }
    if( L->len >= L->listsize )
    {
        ElemType *xe = (ElemType*)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!xe)
        {
            exit(OVERFLOW);
        }
        L->elem = xe;
        L->listsize += LISTINCREMENT;
    }
    int j = 0;
    for(j = L->len;j >= i;j--)
    {
        L->elem[j] = L->elem[j-1];
    }
    L->elem[j] = e;
    L->len++;

    return OK;
}