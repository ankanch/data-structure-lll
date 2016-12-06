#include"KALGraph.h"

Status CreateGraph(KALGraph &G)
{
    //采用数组（邻接矩阵）表示法构造图G
    cout<<"enter kind of graph(DG->0,DN->1,UDG->2,UDN->3):";
    int kind;
    cin>>kind;
    G.kind =  (GraphKind)kind;
    switch(G.kind)
    {
        case GraphKind::DG:
            return 0;
        case GraphKind::DN:
            return 0;
        case GraphKind::UDG:
            return 0;
        case GraphKind::UDN:
            return CreateUDN(G);
        default:
            return ERROR;
    }
}
Status CreateUDN(KALGraph &G)    //构造无向网
{
    
}

int LocateVex(KALGraph &G,VertexType v) //定位顶点v在图中的位置，如果没有，返回-1
{
    
}

Status Input(InfoType & it)        //输入
{
    cin>>it;
    return OK;
}

Status visit(int v)
{
    cout<<v<<" ";
    return OK;
}

int FirstAdjVex(KALGraph G,VertexType v)  //返回v的第一个相邻的顶点
{
    
}
int NextAdjVex(KALGraph G,VertexType v,VertexType w)    //返回v相对于w的下一个邻接顶点
{
    
}

void printGraph(KALGraph G)
{
    cout<<"======== Graph Data Begin======="<<endl;
    cout<<"=Vertxs of Graph:"<<endl;
    
    cout<<endl<<"=Adjacent List of Graph:"<<endl;
    
    cout<<"======== Graph Data End======="<<endl;
}