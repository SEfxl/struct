#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkList;


/**
 * 初始化
 * @param L
 * @return
 */
bool InitLinkList(LinkList &L) {

    L = new Lnode; //生成新节点作为头节点,用头指针L指向头节点

    if (!L) {
        return false;
    }

    L->next = NULL;  //头节点的指针域置空

    return true;

}

/**
 * 每次都插入到头节点之后-头插法
 * @param L
 * @param arr
 * @param length
 */
void CreateLinkList_Head(LinkList &L, const int *arr, int length) {

    LinkList s; //数据节点

    for (int i = 0; i < length; i++) {

        s = (LinkList) malloc(sizeof(Lnode));
        s->data = arr[i];

        s->next = L->next;
        L->next = s;
    }

}

/**
 * 每次都插入到尾节点之后-尾插法
 * @param L
 * @param arr
 * @param length
 */
void CreateLinkList_Tail(LinkList &L, const int *arr, int length) {

    LinkList s; //数据节点
    LinkList r; //一直指向尾节点

    r = L; //开始尾节点指向头指针

    for (int i = 0; i < length; i++) {

        s = (LinkList) malloc(sizeof(Lnode));
        s->data = arr[i];
        s->next = NULL;

        r->next = s; //将数据节点的地址赋值给尾节点的指针域，此时s插入到了r之后
        r = s; //s的地址赋值给r,即r指向新的尾节点

    }

}

/**
 * 在指定位置插入数据
 * @param L
 * @param position
 * @param data
 */
bool InsertPosition(LinkList &L, int position, int data) {

    LinkList s, p = L;

    int j = 0;
    while (p && j < position - 1) {
        p = p->next;
        j++;
    }

    if (!p || j > position - 1) {
        return false;
    }

    s = (LinkList) malloc(sizeof(Lnode));
    s->data = data;

    s->next = p->next;
    p->next = s;

    return true;

}

/**
 * 获取指定位置的值
 * @param L
 * @param position
 * @return
 */
bool getPositionData(LinkList L, int position) {

    LinkList p = L->next;
    int j = 0;
    while (p && j < position - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > position - 1) {
        return false;
    }

    printf("在位置%d的值为:%d\n", position, p->data);
    return true;
}

/**
 * 删除position位置元素
 * @param L
 * @param position
 * @return
 */
bool deletePositionData(LinkList &L, int position) {
    LinkList p=L,q;
    int j = 1;
    while (p->next && j < position) {
        p = p->next;
        j++;
    }

    if(!p->next || j > position) {
        return  false;
    }

    q = p->next;
    p->next = q->next;
    free(q);
    return true;
}


/**
 * 删除值为data的元素
 * @param L
 * @param data
 * @return
 */
bool deleteValueData(LinkList &L, int data) {

    LinkList p=L->next,pre=L,q;

    while (p!= NULL) {

        if(p->data == data) {

            q = p;
            pre->next = q->next;
            p=p->next;
            free(q);

        }else {
            pre = p;
            p = p->next;
        }

    }


}


/**
 * 遍历输出
 * @param L
 */
void Display(LinkList L) {

    LinkList p = L->next;
    printf("遍历链表：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n***********************\n");
}


int main() {


    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(a) / sizeof(int);

    LinkList L; //声明变量
    InitLinkList(L);

    //CreateLinkList_Head(L,a,length);

    CreateLinkList_Tail(L, a, length);
    Display(L);

    bool res = InsertPosition(L, 3, 8);
    printf("插入结果为：%d\n", res);
    Display(L);

    res = getPositionData(L, 3);
    printf("获取结果为：%d\n\n", res);

    res = deletePositionData(L,4);
    printf("位置删除结果为：%d\n", res);
    Display(L);

    res = deleteValueData(L,8);
    printf("值删除结果为：%d\n", res);
    Display(L);
    return 0;

}