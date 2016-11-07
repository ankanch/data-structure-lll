#include<iostream>
#include<stdlib.h>

using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1
#define ERROR 0
#define OK 1

typedef int Status;
typedef char SElemType;
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &s);
Status DestoryStack(SqStack &s);
Status ClearStack(SqStack &s);
Status StackEmpty(SqStack s);
int StackLength(SqStack s);
Status GetTop(SqStack s,SElemType &e);
Status Push(SqStack &s,SElemType e);
Status Pop(SqStack &s,SElemType &e);
Status StackTraverse(SqStack s,Status (*visit)());