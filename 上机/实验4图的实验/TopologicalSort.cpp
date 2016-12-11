#include<iostream>
#include"KALGraph.h"
#include<stack>

using namespace std;

void FindInDegree(KALGraph G,int *&indegree)
{
    for(int i =0;i<G.vexnum;i++)
    {
        int x=0;
        VertexType Lookfor = G.vertices[i].data;
        for(int j=0;j<G.vexnum;j++)
        {
                ArcNode *anp = G.vertices[j].firstarc;
                while( anp != nullptr)
                {
                    if(G.vertices[anp->adjvex].data == Lookfor)
                    {
                        x++;
                    }
                    anp = anp->nextarc;
                }
        }
        indegree[i] = x;
    }
}

stack<int> S;
Status TopologicalSort(KALGraph G)
{
    int count = 0;
    int *indegree = new int[MAX_VERTEX_NUM];
    FindInDegree(G,indegree);
    cout<<"++Indegree Array Start++"<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        cout<<indegree[i]<<"\t";
    }
    cout<<"\n++Indegree Array End++"<<endl;
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