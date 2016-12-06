#include"KMGraph.h"

Status CreateGraph(KMGraph &G)
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
Status CreateUDN(KMGraph &G)    //构造无向网
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
        G.vexs[i] = dta;
    }
        for(int j=0;j<G.vexnum;j++)     //初始化邻接矩阵
        {
            for(int k=0;k<G.vexnum;k++)
            {
                G.arcs[j][k] = {INFINITY,NULL};
            }
        }
        cout<<"please enter v1 v2 and w up to "<<G.arcnum<<" times:"<<endl;
        for(int j=0;j<G.arcnum;j++) //构造邻接矩阵
        {
            VertexType v1,v2;   //顶点
            VRType w;   //权值
            cin>>v1>>v2>>w;
            int x= LocateVex(G,v1);     //确定v1和v2在G中的位置
            int y = LocateVex(G,v2);
            //cout<<"v1="<<v1<<",v2="<<v2<<",w="<<w<<",x="<<x<<",y="<<y<<endl;
            G.arcs[x][y].adj = w;       //弧<v1,v2>的权值
            if(incinfo == 1)            //若弧含有相关信息则输入
            {
                Input(*G.arcs[x][y].info);
            }
            G.arcs[y][x] = G.arcs[x][y];        //设置<v1,v2>的对称弧<v2,v1>
        }
        return OK;
}

int LocateVex(KMGraph &G,VertexType v) //定位顶点v在图中的位置，如果没有，返回-1
{
    //cout<<"in func LocateVexVex("<<v<<")G.vexnum="<<G.vexnum<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i] == v)
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

int FirstAdjVex(KMGraph G,VertexType v)  //返回v的第一个相邻的顶点
{
    int vpos = LocateVex(G,v);
    if(vpos == -1)
    {
        return -1;
    }
    for(int i =0;i<G.vexnum;i++)
    {
        if(G.arcs[vpos][i].adj != INFINITY)
        {
            return i;
        }
    }
    return -1;
}
int NextAdjVex(KMGraph G,VertexType v,VertexType w)    //返回v相对于w的下一个邻接顶点
{
    int vpos = LocateVex(G,v);
    int wpos = LocateVex(G,w);
    //cout<<"vpos="<<vpos<<",wpos="<<wpos<<endl;
    if(vpos == -1)
    {
        return -1;
    }
    for(int i =wpos+1;i<G.vexnum;i++)
    {
        if(G.arcs[vpos][i].adj != INFINITY)
        {
            return i;
        }
    }
    return -1;
}

void printGraph(KMGraph G)
{
    cout<<"======== Graph Data Begin======="<<endl;
    cout<<"=Vertxs of Graph:"<<endl;
    for(int i =0 ;i<G.vexnum;i++)
    {
        cout<<G.vexs[i]<<"\t";
    }
    cout<<endl<<"=Adjacent Martix of Graph:"<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        cout<<"\t";
        for(int j=0;j<G.vexnum;j++)
        {
            VRType t = G.arcs[i][j].adj;
            //cout<<t<<endl;continue;
            if(t == INFINITY)
            {
                cout<<setw(3)<<setiosflags(ios::right)<<"0";
                continue;
            }
            cout<<setw(3)<<setiosflags(ios::right)<<t;
        }
        cout<<endl;
    }
    cout<<"======== Graph Data End======="<<endl;
}