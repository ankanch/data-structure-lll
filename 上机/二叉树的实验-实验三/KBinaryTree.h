#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1
#define ERROR 0
#define OK 1
typedef int Status; 
typedef char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T);
Status PrintElement(TElemType &e);
Status DestoryBiTree(BiTree &T);
Status PreOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status InOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status PostOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status LevelTraverse(BiTree &T,Status(*Visit)(TElemType &e));
int GetBiHeight(BiTree &T);  
Status PrintSpecficLevel(BiTree &T,int level,Status(*Visit)(TElemType &e));
Status InOrderTraverseNoRecursion(BiTree &T,Status(*Visit)(TElemType &e));
Status PreOrderTraverseNoRecursion(BiTree &T,Status(*Visit)(TElemType &e));
//Status PostOrderTraverseNoRecursion(BiTree &T,Status(*Visit)(TElemType &e))
//相关栈===============【为了非递归遍历】==================
//由于g++版本问题，导致直接include 之前的KStack.h会导致重定义。故将必要代码拷贝到这里
typedef int Status;
typedef BiTree SElemType;
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
Status InitStack(SqStack &s);
Status StackEmpty(SqStack s);
Status GetTop(SqStack s,SElemType &e);
Status Push(SqStack &s,SElemType e);
Status Pop(SqStack &s,SElemType &e);


