#include<iostream>
#include"KBinaryTree.h"

using namespace std;

int main(int argc,char **argv)
{
    cout<<">>>enter teaverse sequence then application will set up a Binary Tress satisfied.\n\n(>>>via Recursion<<<)\n"<<endl;
    cout<<">>>Enter here(* for null ):";
    BiTree preT;
    CreateBiTree(preT);
    cout<<"\n>>>now result for PreOrderTraverse():\n\t\t\t\t\t";
    PreOrderTraverse(preT,PrintElement);
    cout<<"\n>>>now result for InOrderTraverse():\n\t\t\t\t\t";
    InOrderTraverse(preT,PrintElement);
    cout<<"\n>>>now result for PostOrderTraverse():\n\t\t\t\t\t";
    PostOrderTraverse(preT,PrintElement);
    cout<<"\n>>>now result for LevelTraverse():\n\t\t\t\t\t";
    LevelOrderTraverse(preT,0,PrintElement);
    cout<<"\n>>>call DestoryBITree()"<<endl;
    DestoryBiTree(preT);
    cout<<">>>resource cleaned"<<endl;
    return 0;
}