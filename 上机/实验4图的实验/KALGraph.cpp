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
    cout<<"enter vex_num arcnum and IncInfo(0=null)(space for split):";
    int incinfo = 0;
    cin>>G.vexnum>>G.arcnum>>incinfo;
    cout<<"start construct UDN Graph..."<<endl;
    cout<<"please enter vertex value up to "<<G.vexnum<<" times:"<<endl;
    for(int i=0;i<G.vexnum;i++)     //构造顶点向量
    {   
        int dta = -1;
        cin>>dta;
        G.vertices[i].data = dta;
    }
        cout<<"please enter v1 v2 up to "<<G.arcnum<<" times:"<<endl;
        for(int j=0;j<G.arcnum;j++) //构造邻接表
        {
            VNode v1={0,NULL},v2={0,NULL};   //顶点
            cin>>v1.data>>v2.data;
            int x= LocateVex(G,v1);     //确定v1和v2在G中的位置
            int y = LocateVex(G,v2);
            ArcNode *px = SeekToEnd(G,x);  //寻找邻接表根部
            ArcNode *py = SeekToEnd(G,y);
            //cout<<"v1="<<v1<<",v2="<<v2<<",w="<<w<<",x="<<x<<",y="<<y<<endl;
            ArcNode *arcx = new ArcNode;   //新的弧（放在x下的）
            arcx->adjvex = y;
            arcx->info = NULL;
            arcx->nextarc = NULL;
            ArcNode *arcy = new ArcNode;   //新的弧（放在y下的）
            arcy->adjvex = x;
            arcy->info = NULL;
            arcy->nextarc = NULL;
            if(incinfo == 1)            //若弧含有相关信息则输入
            {
                Input(*(arcx->info));
                arcy->info = arcx->info;
            }
            px->nextarc = arcx;         //插入邻接表的数据段
            py->nextarc = arcy;
        }
        return OK;
}

int LocateVex(KALGraph &G,VNode v) //定位顶点v在图中的位置，如果没有，返回-1
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data == v.data)
        {
            return i;
        }
    }
    return -1;
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

int FirstAdjVex(KALGraph G,VNode v)  //返回v的第一个相邻的顶点
{
    return -1;   
}
int NextAdjVex(KALGraph G,VNode v,VNode w)    //返回v相对于w的下一个邻接顶点
{
    return -1;
}

ArcNode * SeekToEnd(KALGraph G,int verticesIndex)
{
    ArcNode *anp = G.vertices[verticesIndex].firstarc;
    while(anp != NULL)
    {
        anp = anp->nextarc;
    }
    return anp;
}

void printGraph(KALGraph G)
{
    cout<<"======== Graph Data Begin======="<<endl;
    cout<<"=Vertxs of Graph:"<<endl;
    
    cout<<endl<<"=Adjacent List of Graph:"<<endl;
    
    cout<<"======== Graph Data End======="<<endl;
}