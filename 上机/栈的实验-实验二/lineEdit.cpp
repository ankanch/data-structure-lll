#include<iostream>
#include<string>
#include"KStack.h"

using namespace std;

const bool BracketMatchCheck(const string seq);

int main(int argc,char**argv)
{
    SqStack s;
    InitStack(s);
    char ch = '\0';
    string data = "";
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
        string line = "";
        while(!StackEmpty(s))
        {
            char ppp;
            Pop(s,ppp);
            line=ppp + line;
        }
        data += line;
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


