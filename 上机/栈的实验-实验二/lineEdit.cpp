#include<iostream>
#include<string>
#include"KStack.h"

using namespace std;

string line = "";
string data = "";
Status visit(SElemType e);

int main(int argc,char**argv)
{
    SqStack s;
    InitStack(s);
    char ch = '\0';
    cout<<"line edit application\nCtrl+Z = EXIT"<<endl;
    while(!cin.eof())
    {
        while(!cin.eof() && ch != '\n')
        {
            ch = cin.get();
            char pc = '\0';
            switch(ch)
            {
                case '#':
                    Pop(s,pc);
                    break;
                case '@':
                    ClearStack(s);
                    break;
                default:
                    Push(s,ch);
            }
        }
        
        StackTraverse(s,visit);
        data += line;
        line = "";

        ClearStack(s);
        if(!cin.eof())
        {
            ch = cin.get();
        }
    }
    cout<<"data:\n"<<data<<endl;
    DestoryStack(s);
    return 0;
}

Status visit(SElemType e)
{
    line=e + line;
}

