#include"KBinaryTree.h"
//ȫ�ֱ���
SqStack S;
queue<BiTree> lq;   //���ڲ��α����Ķ���
int level;

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

//下面的3个函数用于层次遍历

int GetBiHeight(BiTree &T)
{
    if (T==NULL)
    {
        return 0;
    }
    else
    {
        int lh = GetBiHeight(T->lchild);
        int rh = GetBiHeight(T->rchild);
        if (lh > rh)
        {
            return(lh+1);
        }
        else 
        {
            return(rh+1);
        }
    }
}

Status PrintSpecficLevel(BiTree &T,int level,Status(*Visit)(TElemType &e))
{
    if (T == NULL)
    {
        return ERROR;
    }
    if (level == 1)
    {
        Visit(T->data);
    }
    else if (level > 1)
    {
        PrintSpecficLevel(T->lchild, level-1,Visit);
        PrintSpecficLevel(T->rchild, level-1,Visit);
    }
    return OK;
}

Status LevelTraverse(BiTree &T,Status(*Visit)(TElemType &e))
{
    int h = GetBiHeight(T);
    for (int i=1; i<=h; i++)
    {
        PrintSpecficLevel(T, i,Visit);
        cout<<endl;
    }
    return OK;
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

//����ջ===============��Ϊ�˷ǵݹ�������==================
//����g++�汾���⣬����ֱ��include ֮ǰ��KStack.h�ᵼ���ض��塣�ʽ���Ҫ���뿽��������
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