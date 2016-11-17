#include"KBinaryTree.h"
#include"KStack.h"

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
Status LevelOrderTraverse(BiTree &T,int level,Status(*Visit)(TElemType &e))
{

}