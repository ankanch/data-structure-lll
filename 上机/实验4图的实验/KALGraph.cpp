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
    cout<<"enter vex_num arcnum and IncInfo(0=nullptr)(space for split):";
    int incinfo = 0;
    cin>>G.vexnum>>G.arcnum>>incinfo;
    cout<<"start construct UDN Graph..."<<endl;
    cout<<"please enter vertex value up to "<<G.vexnum<<" times:"<<endl;
    for(int i=0;i<G.vexnum;i++)     //构造顶点向量
    {   
        int dta = -1;
        cin>>dta;
        G.vertices[i].data = dta;
        G.vertices[i].firstarc = nullptr;
    }
        cout<<"please enter v1 v2 up to "<<G.arcnum<<" times:"<<endl;
        for(int j=0;j<G.arcnum;j++) //构造邻接表
        {
            ArcNode *arcx = new ArcNode;   //新的弧（放在x下的）
            arcx->info = nullptr;
            arcx->nextarc = nullptr; 
            ArcNode *arcy = new ArcNode;   //新的弧（放在y下的）
            arcy->info = nullptr;
            arcy->nextarc = nullptr;
            //输入
            cin>>arcx->adjvex>>arcy->adjvex;
            int x= LocateVex(G,*arcx);     //确定v1和v2在G中的位置
            int y = LocateVex(G,*arcy);
            arcx->adjvex = y;//新的弧（放在x下的）
            arcy->adjvex = x; //新的弧（放在y下的）
            //cout<<",x="<<x<<",y="<<y<<endl;   
            AddToEnd(G,arcx,x);  //接入邻接表
            AddToEnd(G,arcy,y);
            if(incinfo == 1)            //若弧含有相关信息则输入
            {
                Input(*(arcx->info));
                arcy->info = arcx->info;
            }
        }
        return OK;
}

int LocateVex(KALGraph &G,ArcNode v) //定位顶点v在图中的位置，如果没有，返回-1
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data == v.adjvex)
        {
            return i;
        }
    }
    return -1;
}

Status  AddToEnd(KALGraph &G,ArcNode *k,int nodeindex)
{
    //cout<<"1 ";
    if(G.vertices[nodeindex].firstarc == nullptr)
    {
        G.vertices[nodeindex].firstarc = k;
        //cout<<endl;
        return OK;
    }
    ArcNode *anp = G.vertices[nodeindex].firstarc;
    //cout<<"2 ";
    while(anp->nextarc != nullptr)
    {
        //cout<<"+ ";
        anp = anp->nextarc;
    }
    anp->nextarc = k;
    //cout<<"3 "<<endl;
    return OK;
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



void printGraph(KALGraph G)
{
    cout<<"======== Graph Data Begin======="<<endl;
    cout<<"=Vertxs of Graph:"<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        cout<<G.vertices[i].data<<"   ";
    }
    cout<<endl<<"=Adjacent List of Graph:"<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        ArcNode *pac = G.vertices[i].firstarc;
        cout<<G.vertices[i].data<<" :-> ";
        while(pac != nullptr)
        {
            cout<<pac->adjvex<<" -> ";
            pac = pac->nextarc;
        }
        cout<<"\b*"<<endl;
    }
    cout<<"======== Graph Data End======="<<endl;
}