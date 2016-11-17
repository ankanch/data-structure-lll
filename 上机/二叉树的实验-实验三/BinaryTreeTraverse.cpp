#include<iostream>
#include"KBinaryTree.h"

using namespace std;

int main(int argc,char **argv)
{
    cout<<">>>enter teaverse sequence then application will set up a Binary Tress satisfied.\n\n(>>>via Recursion<<<)\n"<<endl;
    cout<<">>>Enter here( # for terminate input):";
    BiTree preT;
    CreateBiTree(preT);

    cout<<">>>call DestoryBITree()"<<endl;
    DestoryBiTree(preT);
    cout<<">>>resource cleaned"<<endl;
    return 0;
}