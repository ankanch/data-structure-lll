#include<iostream>
#include"KBinaryTree.h"

using namespace std;

int main(int argc,char **argv)
{
    cout<<">>>enter teaverse sequence then application will set up a Binary Tress satisfied.\n\n(>>>None Recursion Version<<<)\n"<<endl;
    cout<<">>>Enter here(* for null ):";
    BiTree preT;
    CreateBiTree(preT);
    cout<<"\n>>>now result for InOrderTraverse()->None Recursion:\n\t\t\t\t\t\t\t";
    InOrderTraverseNoRecursion(preT,PrintElement);
    cout<<"\n>>>now result for PreOrderTraverse()->None Recursion:\n\t\t\t\t\t\t\t";
    PreOrderTraverseNoRecursion(preT,PrintElement);
    cout<<"\n>>>call DestoryBITree()"<<endl;
    DestoryBiTree(preT);
    cout<<">>>resource cleaned"<<endl;
    return 0;
}