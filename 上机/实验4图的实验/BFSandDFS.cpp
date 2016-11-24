#include<iostream>
#include"KMGraph.h"
#include<queue>

using namespace std;

#define MAX 20
bool visited[MAX];
Status (*VisitFunc)(int v);
void DFS(KMGraph G,int v)
{
    visited[v] = true;
    VisitFunc(v);
    for(int w= FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
    {
        if(!visited[w])
        {
            DFS(G,w);
        }
    }
}
void DFSTraverse(KMGraph G,Status (*Visit)(int v))
{
    VisitFunc = Visit;
    for(int v=0;v<G.vexnum;v++)
    {
        visited[v] = false;
    }
    for(int v = 0 ;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            DFS(G,v);
        }
    }
}

int main(int argc,char**argv)
{
    KMGraph G;
    CreateGraph(G);
    return 0;
}