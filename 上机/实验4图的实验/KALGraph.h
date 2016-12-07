/*
邻接链表形式
*/
#include<iostream>
#include <iomanip>

using namespace std;

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define INFINITY INT_MAX  //无穷
#define MAX_VERTEX_NUM 20 //最大顶点个数
typedef int Status;
typedef int InfoType; 
typedef int VertexType;
typedef enum{DG,DN,UDG,UDN} GraphKind; //有向图，无向网，无向图，无向网
typedef struct ArcNode{
    int adjvex; //该弧所指向的顶点位置
    struct ArcNode *nextarc; //指向下一条弧的指针
    InfoType *info;     //该弧相关信息的指针
}ArcNode;

typedef struct VNode{
    VertexType data;  //顶点信息
    ArcNode *firstarc;  //指向第一条依附于该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;  //图的当前顶点数和弧数
    int kind;   //图的种类和标志
}KALGraph;

Status CreateGraph(KALGraph &G);
Status CreateUDN(KALGraph &G);    //构造无向网
int LocateVex(KALGraph &G,VNode v); //定位顶点v在图中的位置，如果没有，返回-1
Status Input(InfoType & it);        //输入
Status visit(int v);
ArcNode * SeekToEnd(KALGraph G,int verticesIndex);
int FirstAdjVex(KALGraph G,VNode v);  //返回第一个相邻的顶点
int NextAdjVex(KALGraph G,VNode v,VNode w);    //返回v相对于w的下一个邻接顶点
//调试函数
void printGraph(KALGraph G);
