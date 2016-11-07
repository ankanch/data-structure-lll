#include<iostream>
#include<string>
#include"KStack.h"

using namespace std;

const bool BracketMatchCheck(const string seq);

int main(int argc,char**argv)
{
    string bseq="";
    cout<<"Bracket Match Check\nEXIT for exit\n"<<endl;
    while(bseq != "EXIT")
    {
        cout<<"\nplease enter bracket sequence:";
        cin>>bseq;
        if(!BracketMatchCheck(bseq))
        {
            cout<<"-ERROR:NOT MATCH"<<endl;
        }
        else
        {
            cout<<"-OK:ALL MATCH"<<endl;
        }
    }
    DestoryStack(s);

    return 0;
}

const bool QuickMatch(SElemType rawdata,SElemType comparetarget)
{
    char qm[3]={'(','[','{'};
    char mqm[3]={')',']','}'};
    for(int i=0;i<3;i++)
    {
        if(comparetarget == qm[i])
        {
            if(rawdata == mqm[i])
            {
                return true;
            }
        }
    }
    return false;
}

const bool BracketMatchCheck(const string seq)
{
    SqStack s;
    InitStack(s);
    //start Check
    for(int i=0;i<seq.length();i++)
    {
        if(seq[i]!= '\0')
        {
            SElemType el,raw;
            raw = seq[i];
            GetTop(s,el);
            if(!QuickMatch(raw,el))
            {
                Push(s,raw);
            }
            else
            {
                Pop(s,el);
            }
        }
    }
    if(StackEmpty(s))
    {
        return true;
    }
    return false;


}
