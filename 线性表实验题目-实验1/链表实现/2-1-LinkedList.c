#include<stdio.h>
#include"LinkListArraryImplement.h"

int i = 0;
int La_len=0;
int Lb_len=0;
ElemType e;

void UNION(LinkList La,LinkList Lb)
{
    ///printf("call LinkListLength\n");
    La_len = LinkListLength(La);
    Lb_len = LinkListLength(Lb);
   ///printf("for loop\n");
    for(i = 1;i <= Lb_len;i++)
    {
        ///printf("now call GetElem\n");
        GetElem(Lb,i,&e);
        ///printf("e=%d,now call LocateElem\n",e);
        if(!LocateElem(La,e,equal))
        {
            ///printf("now call LinkListInsert\n");
            LinkListInsert(La,La_len+1,e);   //++La->len
        }
    }
}

int main(int argc,char**argv)
{
    LinkList La,Lb;
    printf("Input 5 numbers:");
    InitLinkList(&La,5);
     PrintLinkList(La);  
    printf("La created!\t\n");
    printf("Input another 5 numbers:");
    InitLinkList(&Lb,5);
    printf("Lb created!\n--------------------\n");

    
    printf("now call function UNION()\n");
    UNION(La,Lb);
    printf("--------------------\nafter call function UNION()\n La:\n");
    PrintLinkList(La);
    DestroyLinkList(La);
    printf("--------------------\nLa Destroied!\t");
    DestroyLinkList(Lb);
    printf("Lb Destroied!\n");
    return 0;
}