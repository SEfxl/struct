#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
    int data;
    struct Lnode *next;
}Lnode,*LinkList;



bool InitLinkList(LinkList &L) {

    L = new Lnode; //生成新节点作为头节点,用头指针L指向头节点

    if( !L ) {
        return false;
    }

    L->next = NULL;  //头节点的指针域置空

    return true;

}

/**
 * @desc 每次都插入到头节点之后
 * @param L
 * @param arr
 * @param length
 */
void CreateLinkList(LinkList &L, const int *arr, int length) {



    LinkList s;


    for (int i = 0; i < length; i++) {
        s = (LinkList) malloc(sizeof(Lnode));

        s->data = arr[i];

        printf("%d ",arr[i]);
        s->next = L->next;
        L->next = s;
    }

}


void Display(LinkList L) {

    LinkList p = L->next;
    while(p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
}

int f(int *x) {
    *x = 2;
}

int main() {



    int a[]= {1,2,3,4,5,6,7,8,9};
    int length = sizeof(a)/ sizeof(int);


    LinkList L; //声明变量
    InitLinkList(L);

    CreateLinkList(L,a,length);
    printf("\n");
    Display(L);



    return 0;

}