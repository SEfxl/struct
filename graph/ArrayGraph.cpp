#include <stdlib.h>
#include <stdio.h>


#define MaxNum 10  //顶点数的最大值


typedef struct Arc {
    char Vex[MaxNum];  //存储顶点信息
    int Edge[MaxNum][MaxNum];  //边上权值的数据类型
    int vexnum,edgenum; //顶点数,边数
}MGragh;

/**
 * @desc 返回当前节点在顶点集合中的下标
 * @param G
 * @param ch
 * @return
 */
int LocateVex(MGragh G, char ch) {

    //printf("vexnum=%d\n",G.vexnum);
    for (int i = 0; i < G.vexnum; i++) {
        if(G.Vex[i] == ch) {
            return i;
        }
    }

}

/**
 * @desc 输出图
 * @param G
 */
void showGraph(MGragh G) {

    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; ++j) {
            printf("%d\t",G.Edge[i][j]);
        }
        printf("\n");
    }
}

/**
 * 邻接矩阵的方式,通过数组存储无向图
 * @param G
 */
void CreateByArray(MGragh G) {

    char u,v;
    int i,j;

    printf("请输入顶点的个数：");
    scanf("%d",&G.vexnum);

    printf("请输入边的个数：");
    scanf("%d",&G.edgenum);

    getchar();
    printf("请输入顶点信息：");
    for (i = 0; i < G.vexnum; i++) {
        scanf("%c",&G.Vex[i]);
    }

    //初始化邻接矩阵所有值为0
    for (int l = 0; l < G.vexnum; l++) {
        for (int k = 0; k < G.vexnum; k++) {
            G.Edge[l][k] = 0;
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
    while (G.edgenum--) {
        getchar();
        scanf("%c%c",&u,&v);
        i = LocateVex(G,u);
        j = LocateVex(G,v);

        if(i != -1 && j != -1) {
            G.Edge[i][j] = G.Edge[j][i] = 1; //邻接矩阵储置1,若为有向图,则G.Edge[i][j]=1
        }

    }

    //输出图
    showGraph(G);
}



int main() {

    MGragh G;
    CreateByArray(G);
    //showGraph(G);

    return 0;

}
