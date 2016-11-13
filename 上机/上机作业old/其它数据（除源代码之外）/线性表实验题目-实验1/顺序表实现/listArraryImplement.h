#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

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
typedef struct
{
    ElemType *elem;
    int len;
    int listsize;
}List;

Status InitList(List *L);
Status DestroyList(List *L);
Status ListLength(List L);
Status GetElem(List L,int i,ElemType *e);
Status LocateElem(List L,ElemType e,ElemType (*f)(ElemType a,ElemType b));
Status ListInsert(List *L,int i,ElemType e);

ElemType equal(ElemType a,ElemType b);