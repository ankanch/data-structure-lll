#include<stdio.h>
#include"listArraryImplement.h"


int i=0,j=0,k=0;
ElemType ai,bj;
void MergeList(List La,List Lb,List *Lc)
{
    InitList(Lc);
    i = j =1;
    k = 0;
    La.len = ListLength(La);
    Lb.len = ListLength(Lb);
    while((i <= La.len) && (j <= Lb.len))
    {
        GetElem(La,i,&ai);
        GetElem(Lb,j,&bj);
        if(ai <= bj)
        {
            ListInsert(Lc,++k,ai);
            ++i;
        }
        else
        {
            ListInsert(Lc,++k,bj);
            ++j;
        }
        while(i <= La.len)
        {
            GetElem(La,i++,&ai);
            ListInsert(Lc,++k,ai);
        }
        while(j <= Lb.len)
        {
            GetElem(Lb,j++,&bj);
            ListInsert(Lc,++k,bj);
        }
    }
}


int main()
{
    List La,Lb,Lc;
    InitList(&La);
    printf("La created!\t");
    InitList(&Lb);
    printf("Lb created!\n");

    int x=0,i=1;
    printf("La :");
    for(x=0;x<5;x+=1,i++)
    {
        ListInsert(&La,i,x);
        printf("%d\t",x);
    }
    printf("\nLb :");
    for(x=5,i=1;x<10;x+=1,i++)
    {
        ListInsert(&Lb,i,x);
        printf("%d\t",x);
    }
    

    printf("\nCALL FUNCTION MergeList()! and create Lc\n--------------------\nLc.elem:\n");
    MergeList(La,Lb,&Lc);

    int t=0;
    for(t=0;t<Lc.len;t++)
    {
        printf("%d\t",Lc.elem[t]);
    }
    printf("\n");

    DestroyList(&La);
    printf("--------------------\nLa Destroied!\t");
    DestroyList(&Lb);
    printf("Lb Destroied!\t");
    DestroyList(&Lc);
    printf("Lc Destroied!\n");

    return 0;
}