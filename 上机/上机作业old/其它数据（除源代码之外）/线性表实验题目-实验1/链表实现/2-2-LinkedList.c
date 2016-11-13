#include<stdio.h>
#include"LinkListArraryImplement.h"


int i=0,j=0,k=0;
int La_len=0;
int Lb_len=0;
ElemType ai,bj;
void MergeLinkList(LinkList La,LinkList Lb,LinkList *Lc)
{
    InitLinkList(Lc,0);
    i = j =1;
    k = 0;
    La_len= LinkListLength(La);
    Lb_len = LinkListLength(Lb);
    while((i <= La_len) && (j <= Lb_len))
    {
        GetElem(La,i,&ai);
        GetElem(Lb,j,&bj);
        if(ai <= bj)
        {
            LinkListInsert(*Lc,++k,ai);
            ++i;
        }
        else
        {
            LinkListInsert(*Lc,++k,bj);
            ++j;
        }
        while(i <= La_len)
        {
            GetElem(La,i++,&ai);
            LinkListInsert(*Lc,++k,ai);
        }
        while(j <= Lb_len)
        {
            GetElem(Lb,j++,&bj);
            LinkListInsert(*Lc,++k,bj);
        }
    }
}


int main()
{
    LinkList La,Lb,Lc;
     printf("Input 5 numbers:");
    InitLinkList(&La,5);
    printf("La created!\t\n");
    printf("Input another 5 numbers:");
    InitLinkList(&Lb,5);
    printf("Lb created!\n-------------------------\n");
    printf("La: ");
    PrintLinkList(La);
    printf("\\nLb: ");
    PrintLinkList(Lb);



/*/
    int x=0,i=1;
    for(x=0;x<10;x+=2,i++)
    {
        LinkListInsert(La,i,x);
    }

    for(x=1,i=1;x<10;x+=2,i++)
    {
        LinkListInsert(Lb,i,x);
    }
/*/
    printf("\nCALL FUNCTION MergeLinkList()! and create Lc\n--------------------\nLc.elem:\n");
    MergeLinkList(La,Lb,&Lc);

    printf("AFTER MergeLinkList() CALLED! \n--------------------\n");
    PrintLinkList(Lc);

    DestroyLinkList(La);
    printf("--------------------\nLa Destroied!\t");
    DestroyLinkList(Lb);
    printf("Lb Destroied!\t");
    DestroyLinkList(Lc);
    printf("Lc Destroied!\n");

    return 0;
}