#include <stdlib.h>
#include <stdio.h>


#define MaxNum 10  //顶点数的最大值

#define  MaxSize 10


//邻接矩阵
typedef struct Arc {
    char Vex[MaxNum];  //存储顶点信息
    int Edge[MaxNum][MaxNum];  //边上权值的数据类型
    int vexnum,edgenum; //顶点数,边数
}MGragh,*Gragh;



/**
 * @desc 返回当前节点在顶点集合中的下标
 * @param G
 * @param ch
 * @return
 */
int LocateVex(Gragh G, char ch) {

    for (int i = 0; i < G->vexnum; i++) {
        if(G->Vex[i] == ch) {
            return i;
        }
    }

}

/**
 * @desc 输出图
 * @param G
 */
void showGraph(Gragh G) {

    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; ++j) {
            printf("%d\t",G->Edge[i][j]);
        }
        printf("\n");
    }
}

/**
 * 邻接矩阵的方式,通过数组存储无向图
 * @param G
 */
void CreateByArray(Gragh &G) {

    char u,v;
    int i,j;

    G = new MGragh; //创建一个实例

    printf("请输入顶点的个数：");
    scanf("%d",&G->vexnum);

    printf("请输入边的个数：");
    scanf("%d",&G->edgenum);

    getchar();
    printf("请输入顶点信息：");
    for (i = 0; i < G->vexnum; i++) {
        scanf("%c",&G->Vex[i]);
    }

    //初始化邻接矩阵所有值为0
    for (int l = 0; l < G->vexnum; l++) {
        for (int k = 0; k < G->vexnum; k++) {
            G->Edge[l][k] = 0;
        }
    }


//    printf("\n\n*************\n");
//    printf("vexnum=%d,edgenum=%d\n",G.vexnum,G.edgenum);
//    for (int k = 0; k < G.vexnum; k++) {
//        printf("%c ",G.Vex[k]);
//    }
//    printf("\n*************\n\n");
//


    printf("请输入每条边依附的两个顶点\n");
    while (G->edgenum--) {
        getchar();
        scanf("%c%c",&u,&v);
        i = LocateVex(G,u);
        j = LocateVex(G,v);

        if(i != -1 && j != -1) {
            G->Edge[i][j] = G->Edge[j][i] = 1; //邻接矩阵储置1,若为有向图,则G.Edge[i][j]=1
        }

    }

}

/**
 * 获取顶点v的第一个邻接顶点的索引,失败则返回-1
 * @param G
 * @param v
 * @return
 */
int FirstVertex(Gragh G, int v) {

    if(v < 0 || v > G->vexnum -1) {
        return  -1;
    }

    for (int j = 0; j < G->vexnum; ++j) {
        if(G->Edge[v][j] == 1) {
            return j;
        }
    }
    return -1;
}

/**
 * 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
 * @param G
 * @param v
 * @param w
 * @return
 */
int NextVertex(Gragh G, int v, int w) {

    int i;

    if (v<0 || v>(G->vexnum-1) || w<0 || w>(G->vexnum-1))
        return -1;

    for (i = w + 1; i < G->vexnum; i++)
        if (G->Edge[v][i] == 1)
            return i;

    return -1;

}


/**
 * DFS 广度优先遍历-类似于图的层次遍历
 * @param G
 */
void BFS(Gragh G) {

    int head = 0;
    int rear = 0;
    int queue[MaxSize];     // 辅组队列
    int visited[MaxSize];   // 顶点访问标记
    int i, j, k;

    for (i = 0; i < G->vexnum; i++)
        visited[i] = 0;

    printf("BFS遍历依次为: ");
    for ( i = 0; i < G->vexnum; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            printf("%c ",G->Vex[i]);
            queue[rear++] = i; //入队列
        }

        while (head != rear) { //队列不空

            j = queue[head++]; //出队列
            for (k=FirstVertex(G,j); k >= 0; k = NextVertex(G,j,k)) {
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%c ", G->Vex[k]);
                    queue[rear++] = k;
                }
            }

        }
    }
    printf("\n");

}


int visited[MaxSize];
void DFS(Gragh G, char ch) {

    int index;

    index = LocateVex(G,ch); //获取该节点的存储下标 
    visited[index] = 1; //标记为已访问
    
    printf("%c ",ch);
    for (int i = 0; i < G->vexnum; i++) {
        if(!visited[i] && G->Edge[index][i]) {
            DFS(G,G->Vex[i]);
        }
    }
    

}

/**
 * 输入demo
 * 4
 * 5
 * abcd
 * ab
 * ad
 * bc
 * bd
 * cd
 */
int main() {

    Gragh G;
    CreateByArray(G);

    //输出图
    showGraph(G);

    //BFS遍历
    BFS(G);

    //DFS遍历
    printf("DFS遍历依次为: ");
    DFS(G,'a');

    return 0;

}
