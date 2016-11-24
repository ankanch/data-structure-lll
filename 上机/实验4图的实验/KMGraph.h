#include<iostream>

using namespace std;

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define INFINITY INT_MAX  //无穷
#define MAX_VERTEX_NUM 20 //最大顶点个数
typedef int Status;
typedef unsigned int VRType;
typedef int InfoType; 
typedef char VertexType;
typedef enum{DG,DN,UDG,UDN} GraphKind; //有向图，无向网，无向图，无向网
typedef struct ArcCell{
    VRType adj;  //VRType是顶点关系类型。对无权图，用1或0
                //表示相邻否；对带权图，则为权值类型
    InfoType *info; //该弧相关信息的指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
    VertexType vexs[MAX_VERTEX_NUM];    //顶点向量
    AdjMatrix arcs;                     //邻接矩阵
    int vexnum,arcnum;                  //图的当前顶点数和弧数
    GraphKind kind;                     //图的种类表示
}KMGraph;

Status CreateGraph(KMGraph &G);
Status CreateUDN(KMGraph &G);    //构造无向网
int LocateVex(KMGraph &G,VertexType v); //定位顶点v在图中的位置，如果没有，返回-1
Status Input(InfoType & it);        //输入
