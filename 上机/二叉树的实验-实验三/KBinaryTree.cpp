#include"KBinaryTree.h"

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
        //cout<<T->data<<endl;
        if( T->lchild != NULL )
        {
            DestoryBiTree(T->lchild);
        }
        if( T->rchild != NULL )
        {
            DestoryBiTree(T->rchild);
        }
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
    if( T!= NULL )
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild,Visit);
        PreOrderTraverse(T->rchild,Visit);
    }
    return OK;
}
Status InOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status PostOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status LevelOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));