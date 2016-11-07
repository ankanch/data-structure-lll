#include"KStack.h"


Status InitStack(SqStack &s)
{
    s.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!s.base)
    {
        exit(OVERFLOW);
    }
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack s,SElemType &e)
{
    if(s.top == s.base)
    {
        return ERROR;
    }
    e = *(s.top-1);
    return OK;
}

Status Push(SqStack &s,SElemType e)
{
    if(s.top - s.base >= s.stacksize)
    {
        s.base = (SElemType*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
    
        if(!s.base)
        {
            exit(OVERFLOW);
        }
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}

Status Pop(SqStack &s,SElemType &e)
{
    if(s.top == s.base)
    {
        return ERROR;
    }
    e = * --s.top;
    return OK;
}

Status StackEmpty(SqStack s)
{
    if(s.top == s.base)
    {
        return OK;
    }
    return ERROR;
}

Status DestoryStack(SqStack &s)
{
    free(s.base);
}

Status ClearStack(SqStack &s)
{
    free(s.base);
    InitStack(s);
}