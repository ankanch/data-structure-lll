#include<iostream>
#include"KALGraph.h"
#include<stack>

using namespace std;

stack<int> S;
Status TopologicalSort(KALGraph G)
{
    int count = 0;
    FindInDegree(G,indegree);
    for(int i=0;i<G.vexnum;i++)
    {
        if(!indegree[i])
        {
            S.push(i);
        }
    }
    while(!S.empty())
    {
        int i = S.top();
        S.pop();
        cout<<i<<","<<G.vertices[i].data<<endl;
        count++;
        for(ArcNode p = G.vertices[i].firstarc;p;p=p->nextarc)
        {
            int k = p->adjvex;
            if(!(--indegree[k]))
            {
                S.push(k);
            }
        }
    }
    if(count<G.vexnum)
    {
        return ERROR;
    }
    return OK;
}

int main(int argc,char**argv)
{
    KMGraph G;
    CreateGraph(G);
    printGraph(G);
    cout<<endl<<endl<<"+++start Topological Sort... "<<endl;
    TopologicalSort(G);
    cout<<endl<<endl<<"+++done."<<endl;
    return 0;
}