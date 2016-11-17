#include<iostream>
#include<stdlib.h>

using namespace std;

#define OVERFLOW -1
#define ERROR 0
#define OK 1

//二叉树定义
typedef int Status; 
typedef char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T);  //先序建立二叉树
Status PrintElement(TElemType &e);
Status DestoryBiTree(BiTree &T);



//二叉树遍历
Status PreOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status InOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status PostOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));
Status LevelOrderTraverse(BiTree &T,Status(*Visit)(TElemType &e));