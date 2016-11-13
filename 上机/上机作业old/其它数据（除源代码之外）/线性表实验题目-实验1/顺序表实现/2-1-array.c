#include<stdio.h>
#include"listArraryImplement.h"

int i = 0;
ElemType e;

void UNION(List *La,List Lb)
{
    La->len = ListLength(*La);
    Lb.len = ListLength(Lb);
    for(i = 1;i<=Lb.len;i++)
    {
        GetElem(Lb,i,&e);
        //printf("e=%d\n",e);
        if(!LocateElem(*La,e,equal))
        {
            //printf("e=%d\tlocated failed",e);
            ListInsert(La,La->len+1,e);   //++La->len
        }
    }
}

int main(int argc,char**argv)
{
    List La,Lb;
    InitList(&La);
    printf("La created!\t");
    InitList(&Lb);
    printf("Lb created!\n--------------------\n");

    int x=0,i=1;
    for(x=2,i=1;x<8;x+=2,i++)
    {
        ListInsert(&La,i,x);
        printf("%d\t",x);
    }
    printf("\n");
    for(x=0,i=1;x<8;x+=3,i++)
    {
        ListInsert(&Lb,i,x);
        printf("%d\t",x);
    }
    printf("\nBEFORE FUNCTION CALL:\nLa.len=%d\tLa.listsize=%d\nLb.len=%d\tLb.listsize=%d\n",La.len,La.listsize,Lb.len,Lb.listsize);
    
    printf("now call function UNION()\n");
    UNION(&La,Lb);
    printf("AFTER FUNCTION CALL:\nLa.len=%d\tLa.listsize=%d\nLb.len=%d\tLb.listsize=%d\n",La.len,La.listsize,Lb.len,Lb.listsize);
    int t=0;
    for(t=0;t<La.len;t++)
    {
        printf("%d\t",La.elem[t]);
    }
    printf("\n");

    DestroyList(&La);
    printf("--------------------\nLa Destroied!\t");
    DestroyList(&Lb);
    printf("Lb Destroied!\n");
    return 0;
}