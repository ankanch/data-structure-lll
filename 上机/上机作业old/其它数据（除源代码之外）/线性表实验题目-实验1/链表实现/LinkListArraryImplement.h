#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define LinkList_INIT_SIZE 100
#define LinkListINCREMENT 10

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

typedef int ElemType;
typedef int Status;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status InitLinkList(LinkList *L,int n);
Status DestroyLinkList(LinkList L);
Status GetElem(LinkList L,int i,ElemType *e);
Status LocateElem(LinkList L,ElemType e,ElemType (*f)(ElemType a,ElemType b));
Status LinkListInsert(LinkList  L,int i,ElemType e);
Status LinkListLength(LinkList L);
void PrintLinkList(LinkList L);   //test function

ElemType equal(ElemType a,ElemType b);