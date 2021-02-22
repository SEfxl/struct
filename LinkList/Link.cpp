#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
    int data;
    struct Lnode *next;
} Lnode, *LinkList;

LinkList afterSourceNode = NULL;


/**
 * 迭代输出链表
 * @param L
 * @return
 */
LinkList reverseLinkIteration(LinkList L) {

    if(L == NULL) {
        return NULL;
    }

    LinkList pre,cur,nex;
    pre = NULL;
    cur = L;
    nex = L;

    while (cur != NULL) {
        nex = cur->next; //当前节点的下一个节点
        cur->next = pre; //指针指向前面一个节点

        pre = cur; //pre指针节点后移
        cur = nex; //cur指针节点后移
    }
    return pre; //反转后的头节点
}


/**
 * 将L和B节点之间的数据进行反转
 * @param L
 * @param B
 * @return
 */
LinkList reverseLToB(LinkList L, LinkList B) {

    printf("L=%d B= %d\n",L->data,B->data);
    LinkList pre,cur,nex;
    pre = NULL;
    cur = L;
    nex = L;


    while (cur != B) {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }

    L->next = nex; //将反转后节点和没有反转的节点进行链接

    return pre;
}



/**
 * 递归反转链表
 * @param head
 * @return
 */
LinkList recursion(LinkList head) {

   if(head == NULL || head->next == NULL) { //节点为空则直接返回 只有一个节点,不需要反转
       return head;
   }

   LinkList p = recursion(head->next); //递归遍历至最后一个节点,从后面的节点向前反转

   head->next->next = head; //将当前节点设置为后一个节点的后续节点

   head->next = NULL; //将当前节点的next指针置为NULL, 当递归回溯到第一个节点，尾节点正好也是NULL

   return p; //返回反转后链表的头指针

}


/**
 * 反转链表前n个节点
 * @param head
 * @param n
 * @return
 */
LinkList reversePreNode(LinkList head, int n) {

    if(n == 1) {
        afterSourceNode = head->next; // 记录需要反转节点的在一个节点
        return head;
    }

    LinkList p = reversePreNode(head->next, n-1);

    head->next->next = head;
    head->next = afterSourceNode;
    return  p;

}

/**
 * 递归反转链表m-n区间的节点
 * @param head
 * @param m
 * @param n
 * @return
 */
LinkList reverseMtoNNode(LinkList head, int m,int n) {

    if(m== 1) {
        return reversePreNode(head,n);
    }

    //前进到反转的起点触发
    head->next = reverseMtoNNode(head->next,m-1,n-1);

    return head;

}

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
    LinkList p = L, q;
    int j = 1;
    while (p->next && j < position) {
        p = p->next;
        j++;
    }

    if (!p->next || j > position) {
        return false;
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
void deleteValueData(LinkList &L, int data) {

    LinkList p = L->next, pre = L, q;

    while (p != NULL) {

        if (p->data == data) {

            q = p;
            pre->next = q->next;
            p = p->next;
            free(q);

        } else {
            pre = p;
            p = p->next;
        }

    }


}

/**
 * 获取中间节点
 * @param L
 */
void getMiddleNode(LinkList L) {

    LinkList p1, p2;
    p1 = L;
    p2 = L;
    while (p2 != NULL) {
        if (p2->next != NULL) {
            p2 = p2->next->next;
        } else {
            break;
        }

        p1 = p1->next;

    }

    printf("快慢指针,中间节点为：%d\n", p1->data);

}

/**
 * 获取倒数第n个节点
 * @param L
 * @param n
 * @return
 */
bool getBackCountNode(LinkList L, int n) {

    if (L == NULL || n == 0) {
        return false;
    }

    LinkList p = L, q = L;
    for (int i = 0; i < n; i++) {
        if (q) {
            q = q->next;
        } else {
            return false;
        }
    }

    while (q != NULL) {
        p = p->next;
        q = q->next;
    }
    printf("倒数第%d个节点为:%d\n", n, p->data);

    return true;
}

/**
 * 链表反转
 * @param L
 */
void reverseLinkList(LinkList &L) {
    LinkList p1, p2, p3, s;
    p1 = L;
    p2 = L->next;
    while (p2 != NULL) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    L->next = NULL;

    //构造一个头节点
    s = (LinkList) malloc(sizeof(Lnode));
    s->next = p1;
    L = s;

}


/**
 * 链表是否有环
 * @param L
 * @return
 */
//bool hasCircle(LinkList L) {
//    LinkList fast,low;
//    fast = L;
//    low = L;
//    while(slow != NULL && fast->next != NULL) { //没有到达链表尾部则继续前进
//        fast = fast->next->next;
//        low = low->next;
//        if(fast == low) { //两指针相遇
//            return true;
//        }
//    }
//
//    return false; //到达结尾没有相遇
//
//}


/**
 * 链表合并：依次比较p1,p2,将小的值依次插入L中
 * @param L
 * @param p1
 * @param p2
 */
void mergeLinkList(LinkList &L, LinkList p1, LinkList p2) {
    LinkList s, r = L;
    p1 = p1->next;
    p2 = p2->next;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            s = (LinkList) malloc(sizeof(Lnode));
            s->data = p1->data;
            s->next = NULL;

            r->next = s;
            r = s;

            p1 = p1->next;
        } else {
            s = (LinkList) malloc(sizeof(Lnode));
            s->data = p2->data;
            s->next = NULL;

            r->next = s;
            r = s;

            p2 = p2->next;
        }

    }

    while (p1 != NULL) {
        s = (LinkList) malloc(sizeof(Lnode));
        s->data = p1->data;
        s->next = NULL;

        r->next = s;
        r = s;

        p1 = p1->next;
    }

    while (p2 != NULL) {
        s = (LinkList) malloc(sizeof(Lnode));
        s->data = p2->data;
        s->next = NULL;

        r->next = s;
        r = s;

        p2 = p2->next;
    }

}

/**
 * 链表合并：依次比较两个链表的值,用head依次将他们串联起来
 * @param L1
 * @param L2
 * @return
 */
LinkList mergeLinkList_2(LinkList &L1, LinkList &L2) {

    LinkList head, tail; //head新链表的头节点,tail新链表的尾节点

    if (L1 == NULL) {
        return L2;
    } else if (L2 == NULL) {
        return L1;
    } else {
        //去除头节点
        L1 = L1->next;
        L2 = L2->next;

        if (L1->data <= L2->data) {
            head = L1;
            L1 = L1->next;
        } else {
            head = L2;
            L2 = L2->next;
        }

        tail = head;

        while (L1 && L2) {
            if (L1->data <= L2->data) {
                tail->next = L1;
                tail = L1;
                L1 = L1->next;
            } else {
                tail->next = L2;
                tail = L2;
                L2 = L2->next;
            }
        }

        if (L1 == NULL) {
            tail->next = L2;
        } else if (L2 == NULL) {
            tail->next = L1;
        }

        return head;

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
    printf("\n\n***********************\n");
}

void DisplayFromHead(LinkList L) {

    printf("DisplayFromHead：");
    LinkList p = L;
    while (p != NULL && p->next != NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n\n");

}

void TestmergeLinkList() {

    LinkList L, L1, L2; //声明变量

    int a[] = {1, 2, 3, 4, 5};
    int length_1 = sizeof(a) / sizeof(int);
    InitLinkList(L1);
    CreateLinkList_Tail(L1, a, length_1);
    Display(L1);


    int b[] = {1, 4, 5, 6, 7, 8};
    int length_2 = sizeof(b) / sizeof(int);
    InitLinkList(L2);
    CreateLinkList_Tail(L2, b, length_2);
    Display(L2);

    InitLinkList(L);
    mergeLinkList(L, L1, L2);
    Display(L);

}

int mergeLinkList_2() {

    LinkList L, L1, L2; //声明变量

    int a[] = {1, 2, 3, 4, 5};
    int length_1 = sizeof(a) / sizeof(int);
    InitLinkList(L1);
    CreateLinkList_Tail(L1, a, length_1);
    Display(L1);


    int b[] = {1, 4, 5, 6, 7, 8};
    int length_2 = sizeof(b) / sizeof(int);
    InitLinkList(L2);
    CreateLinkList_Tail(L2, b, length_2);
    Display(L2);

    L = mergeLinkList_2(L1, L2);
    Display(L);
    return 0;

}

int main() {


    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof(int);

    LinkList L,B; //声明变量

    InitLinkList(L);
    //CreateLinkList_Head(L,a,length);
    CreateLinkList_Tail(L, a, length);
    getMiddleNode(L);
    Display(L);

//    B = L->next->next->next;
//    printf("cur node = %d\n",B->data);
//    LinkList LB = reverseLToB(L,L->next->next->next->next->next);
//    DisplayFromHead(LB);


//    LinkList r = reverseLinkIteration(L);
//    printf("迭代输出链表:");
//    DisplayFromHead(r);

//    LinkList p = recursion(L);
//    printf("递归反转链表-> ");
//    DisplayFromHead(p);

//    LinkList p1 = reversePreNode(L->next,3);
//    printf("递归反转前3个链表节点-> ");
//    DisplayFromHead(p1);

//    LinkList p2 = reverseMtoNNode(L->next,3,6);
//    printf("递归反转前3-6区间链表节点-> ");
//    DisplayFromHead(p2);


    getBackCountNode(L, 3);

    bool res = InsertPosition(L, 3, 8);
    printf("插入结果为：%d\n", res);
    getMiddleNode(L);
    Display(L);

    res = getPositionData(L, 3);
    printf("获取结果为：%d\n\n", res);

    res = deletePositionData(L, 4);
    printf("位置删除结果为：%d\n", res);
    Display(L);

    deleteValueData(L, 8);
    Display(L);

    reverseLinkList(L);
    Display(L);
    

    return 0;

}