#include <stdio.h>
#include <stdlib.h>

//邻接点用到两个数据结构：顶点节点和邻接点节点
// 顶点节点：包括顶点信息和指向第一个邻接点的指针，可用一维数组存储
// 邻接点节点：包括邻接点的存储下标和指向下一个邻接点和指针

//邻接点
typedef struct AdjNode {
    int v;  //邻接点下标
    struct AdjNode *next;  //指向下一个邻接点
}AdjNode,*ANode;


//顶点
typedef struct VexNode {
    char data;
    ANode first; //指向第一个邻节点
}VexNode;

#define MaxVnum 100 //顶点数最大值


//图的邻接表存储
typedef struct ALGragh {
    VexNode Vex[MaxVnum];
    int vexnum;   //顶点数
    int edgenum;  //边数
}ALGragh,*Gragh;

/**
 * @desc 获取元素在顶点集合中的下标
 * @param G
 * @param ch
 * @return
 */
int getElementIndex(Gragh G, char ch) {
    for (int i = 0; i < G->vexnum; i++) {
        if(G->Vex[i].data == ch) {
            return  i;
        }
    }
}

/**
 * @desc 使用头插法,插入邻接点
 * @param G
 * @param i
 * @param j
 */
void insertEdge(Gragh &G,int i,int j) {

    ANode s;
    s =(ANode) malloc(sizeof(AdjNode));

    s->v = j;
    s->next = G->Vex[i].first;
    G->Vex[i].first = s;
}

void CreateALGragh(Gragh &G) {

    G = new ALGragh;

    char u,v;
    int i,uIndex,vIndex;

    printf("请输入顶点数:");
    scanf("%d",&G->vexnum);

    getchar();
    printf("请输入边数:");
    scanf("%d",&G->edgenum);

    getchar();
    printf("请依次输入%d个顶点信息:",G->vexnum);
    for (i = 0; i < G->vexnum ; i++) {
        scanf("%c",&G->Vex[i].data);
    }

    for (i = 0; i < G->vexnum ; i++) {
        G->Vex[i].first = NULL;
    }

    printf("请依次输入每条边的两个顶点（总计%d条边）:\n",G->edgenum);
    for (int k = 0; k < G->edgenum; k++) {
        getchar();
        scanf("%c%c",&u,&v);
        uIndex = getElementIndex(G,u);
        vIndex = getElementIndex(G,v);

        insertEdge(G,uIndex,vIndex);
    }

}

/**
 * @desc 输出邻接链表的信息
 * @param G
 */
void DisplayALGragh(Gragh G) {

    printf("顶点数: %d, 边数: %d \n",G->vexnum,G->edgenum);

    for (int i = 0; i < G->vexnum; i++) {

        //输出顶点信息
        printf("顶点:%c ",G->Vex[i].data);

        //输出邻接点信息
        ANode s;
        s = G->Vex[i].first;

        if(s != NULL) {
            printf("邻接点:");
        }else {
            printf("没有邻接点");
        }
        while (s != NULL) {
            printf("index=%d,value=%c  ",s->v,G->Vex[s->v].data);
            s = s->next;
        }
        printf("\n");
    }

}

/** 输入demo
 * 5
 * 7
 * abcde
 * ab
 * ac
 * ae
 * bc
 * cd
 * ce
 * de
 * **/
int main() {

    Gragh G;
    CreateALGragh(G);
    DisplayALGragh(G);

    return 0;
}