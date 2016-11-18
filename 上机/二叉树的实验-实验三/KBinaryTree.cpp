#include"KBinaryTree.h"
//全局变量
SqStack S;
queue<BiTree> lq;   //用于层次遍历的队列

Status CreateBiTree(BiTree &T)
{
    TElemType ch = 0;
    cin.get(ch);
    if(ch == '\n')
    {
        cin.get(ch);
    }
    if( ch==' ' )
    {
        T = NULL;
    }
    else
    {
        if( !(T=(BiTNode*)malloc(sizeof(BiTNode))) )
        {
            return ERROR;
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

Status DestoryBiTree(BiTree &T)
{
    if(T != NULL)
    {
        if( T->lchild != NULL )
        {
            DestoryBiTree(T->lchild);
        }
        if( T->rchild != NULL )
        {
            DestoryBiTree(T->rchild);
        }
        //cout<<T->data<<endl;
        free(T);
    }
}

Status PrintElement(TElemType &e)
{
    cout<<e;
    return OK;
}

Status PreOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e))
{
    if( T != NULL)
    {
        Visit(T->data);
        if(!PreOrderTraverse(T->lchild,Visit))
        {
            return ERROR;
        }
        if(!PreOrderTraverse(T->rchild,Visit))
        {
            return ERROR;
        } 
    }
    return OK;
}
Status InOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e))
{
    if( T != NULL)
    {
        if(!InOrderTraverse(T->lchild,Visit))
        {
            return ERROR;
        }
        Visit(T->data);
        if(!InOrderTraverse(T->rchild,Visit))
        {
            return ERROR;
        } 
    }
    return OK;
}
Status PostOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e))
{
    if( T != NULL)
    {
        if(!PostOrderTraverse(T->lchild,Visit))
        {
            return ERROR;
        }
        if(!PostOrderTraverse(T->rchild,Visit))
        {
            return ERROR;
        }
        Visit(T->data); 
    }
    return OK;
}
Status LevelTraverse(BiTree &T,int &count,Status(*Visit)(TElemType &e))
{
    //thinking.... 
    if( count == 0 )  //说明是第一次
    {
        lq.push(T);
    }
    if(!lq.empty())
    {
        BiTree head = lq.front();
        lq.pop();
        if( head != NULL)
        {
            Visit(head->data);
            lq.push(head->lchild);
            lq.push(head->rchild);
            LevelTraverse(T,++count,Visit);
        }
        LevelTraverse(T,++count,Visit);
    }
    else
    {
        return OK;
    }
}

Status InOrderTraverseNoRecursion(BiTree &T,Status(*Visit)(TElemType &e))
{
    SElemType p;
    InitStack(S);
    Push(S,T);
    while(!StackEmpty(S))
    {
        while( GetTop(S,p) && p )
        {
            Push(S,p->lchild);
        }
        Pop(S,p);
        if(!StackEmpty(S))
        {
            Pop(S,p);
            if(!Visit(p->data))
            {
                return ERROR;
            }
            Push(S,p->rchild);
        }
    }
    return OK;
}

//相关栈===============【为了非递归遍历】==================
//由于g++版本问题，导致直接include 之前的KStack.h会导致重定义。故将必要代码拷贝到这里
Status InitStack(SqStack &s)
{
    s.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!s.base)
    {
        exit(OVERFLOW);
    }
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack s,SElemType &e)
{
    if(s.top == s.base)
    {
        return ERROR;
    }
    e = *(s.top-1);
    return OK;
}

Status Push(SqStack &s,SElemType e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (SElemType*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
    
        if(!s.base)
        {
            exit(OVERFLOW);
        }
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}

Status Pop(SqStack &s,SElemType &e)
{
    if(s.top == s.base)
    {
        return ERROR;
    }
    e = * --s.top;
    return OK;
}

Status StackEmpty(SqStack s)
{
    if(s.top == s.base)
    {
        return OK;
    }
    return ERROR;
}
