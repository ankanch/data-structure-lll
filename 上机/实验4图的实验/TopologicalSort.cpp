#include<iostream>
#include"KALGraph.h"
#include<stack>

using namespace std;

void FindInDegree(KALGraph G,int *&indegree)
{
    for(int i =0;i<G.vexnum;i++)
    {
        if(G.vertices[i].firstarc != nullptr)
        {
            ArcNode *anp=G.vertices[i].firstarc;
            int x = 0;
            while(anp->nextarc != nullptr)
            {
                x++;
                anp = anp->nextarc;
            }
            indegree[i] = x;
        }
        else
        {
            indegree[i] = 0;
        }
    }
}

stack<int> S;
Status TopologicalSort(KALGraph G)
{
    int count = 0;
    int *indegree = new int[MAX_VERTEX_NUM];
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
        for(ArcNode *p = G.vertices[i].firstarc;p;p=p->nextarc)
        {
            int k = p->adjvex;
            if(!(--indegree[k]))
            {
                S.push(k);
            }
        }
    }
    delete[] indegree;
    if(count<G.vexnum)
    {
        return ERROR;
    }
    return OK;
}



int main(int argc,char**argv)
{
    KALGraph G;
    CreateGraph(G);
    printGraph(G);
    cout<<endl<<endl<<"+++start Topological Sort... "<<endl;
    TopologicalSort(G);
    cout<<endl<<endl<<"+++done."<<endl;
    return 0;
}