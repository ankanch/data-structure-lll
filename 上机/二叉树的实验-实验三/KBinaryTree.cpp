#include"KBinaryTree.h"

Status CreateBiTree(BiTree &T)
{
    TElemType ch = 0;
    cin>>ch;
    if( ch=='#' )
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
        free(T);
    }
    else{
        if( T->lchild != NULL )
        {
            DestoryBiTree(T->lchild);
        }
        if( T->rchild != NULL )
        {
            DestoryBiTree(T->rchild);
        }
    }
}