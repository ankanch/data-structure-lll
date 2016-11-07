#include<stdlib.h>
#include<stdio.h>
#include"LinkListArraryImplement.h"

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

Status InitLinkList(LinkList  *L,int n)
{
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    int i = 0;
    for(i = n;i>0;--i)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }  
}

void PrintLinkList(LinkList L)
{
    LinkList x = L;
    int i =0;
    printf("print LinkList: ");
    while( x->next != NULL)
    {
        x = x->next;
        printf("%d,",x->data);
        i++;
    }
    printf("count=%d\n",i);
}

Status DestroyLinkList(LinkList L)
{
    LinkList p = L->next;
    LinkList pr = L;
    while( pr->next != NULL )
    {
        p = pr->next;
        free(pr);
        pr = p;
    }
    free(pr);
    return OK;
}

Status GetElem(LinkList L,int i,ElemType *e)
{
    LinkList p = L->next;
    int j = 1;
    while( p && j<i )
    {
        p = p->next;
        ++j;
    }
    if( !p || j>i)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status LocateElem(LinkList L,ElemType e,ElemType (*f)(ElemType a,ElemType b))
{
    LinkList p = L->next;
    int i=0;
    while( p!= NULL )
    {
        if(p->data == f(p->data,e))
        {
            return (i+1);
        }
        p = p->next;
        i++;
    }
    return ERROR;
}

ElemType equal(ElemType a,ElemType b)
{
    if(a == b)
    {
        return a;
    }
    return 99999;
}

Status LinkListLength(LinkList L)
{
    LinkList x = L;
    int i =0;
    //printf("in function LinkListLength : ");
    while( x->next != NULL)
    {
        x = x->next;
        //printf("%d,",x->data);
        i++;
    }
    //printf("count=%d\n",i);
    return i;
}

Status LinkListInsert(LinkList  L,int i,ElemType e)
{
    LinkList p = L;
    int j = 0;
    while( p && j<i-1 )
    {
        p = p->next;
        ++j;
    }
    if( !p || j > i-1 )
    {
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}