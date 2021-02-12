#include <stdio.h>
#include <stdlib.h>

#define  MaxSize 10

typedef struct SqQueue {
    int *base;
    int front, real;
} SqQueue;

void InitQueue(SqQueue *&q) {
    q->base = new int[MaxSize];
    q->front = q->real = 0;
    printf("初始化队列完\n");
}


bool enQueue(SqQueue *&q, int data) {

    if ((q->real + 1) % MaxSize == q->front) {
        printf("队列满了, 数据：%d \n", data);
        return false;
    }

    //printf("q->real = %d  data=%d \n",q->real,data);
    q->base[q->real] = data;
    q->real = (q->real + 1) % MaxSize;

    return true;
}

bool deQueue(SqQueue *&q) {

    if (q->real == q->front) {
        printf("队列为空,无法出队\n");
        return false;
    }

    printf("出队数据为：%d\n", q->base[q->front]);
    q->front = (q->front + 1) % MaxSize;
    return true;

}

/**
 * 获取队首元素
 * @param q
 * @return
 */
int getFrontElement(SqQueue *q) {

    printf("real=%d  front=%d\n",q->real,q->front);
    //return 666;
    if (q->front == q->real) {
        printf("队列为空\n");
        return -1;
    }

    return q->base[q->front];
}

/**
 * 队列中元素个数
 * @param q
 * @return
 */
int getQueueElementNum(SqQueue *q) {

    return (q->real - q->front + MaxSize) % MaxSize;

}

//环形队列,约定在进队时少用一个数据元素空间
//队满条件：(q->real + 1) % MaxSize = q->front
//队空条件：q->real = q->front
int main() {

    SqQueue *q;
    InitQueue(q);

    for (int i = 1; i < 12; i++) {
        enQueue(q, i);
    }

    printf("real=%d  front=%d\n",q->real,q->front);



    deQueue(q);

    int nums = getQueueElementNum(q);
    printf("队列中元素个数为：%d\n", nums);

    int frontElement = getFrontElement(q);
    printf("队首元素为：%d\n", frontElement);


    return 0;
}