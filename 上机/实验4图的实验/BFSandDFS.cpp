#include<iostream>
#include"KMGraph.h"
#include<queue>

using namespace std;

#define MAX 20
bool visited[MAX] = {false};
Status (*VisitFunc)(int v);
void DFS(KMGraph G,int v)
{
    visited[v] = true;
    VisitFunc(G.vexs[v]);
    for(int w= FirstAdjVex(G,G.vexs[v]);w>=0;w=NextAdjVex(G,G.vexs[v],G.vexs[w]))
    {
        //cout<<"w="<<w<<endl;
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

queue<VertexType> Q;
void BFSTraverse(KMGraph G,Status (*Visit)(int v))
{
    for(int v=0;v<G.vexnum;++v)
    {
        visited[v] = false;
    }
    for(int v=0;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            visited[v]=true;
            Visit(G.vexs[v]);
            Q.push(G.vexs[v]);
            while(!Q.empty())
            {
                VertexType u = Q.front();
                Q.pop();
                for(int w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,G.vexs[w]))
                {
                    if(!visited[w])
                    {
                        visited[w] = true;
                        Visit(G.vexs[w]);
                        Q.push(G.vexs[w]);
                    }
                }
            }
        }
    }
    
}

int main(int argc,char**argv)
{
    KMGraph G;
    CreateGraph(G);
    printGraph(G);
    cout<<endl<<endl<<"+++start Depth_First_Search... "<<endl;
    cout<<"DFS : ";
    DFSTraverse(G,visit);
    cout<<endl<<endl<<"+++start Breadth_First_Search... "<<endl;
    cout<<"BFS : ";
    BFSTraverse(G,visit);
    cout<<endl<<endl<<"+++done."<<endl;
    
    return 0;
}