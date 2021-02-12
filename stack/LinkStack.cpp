#include <stdio.h>
#include <stdlib.h>

//链栈

typedef struct Snode {
    int data;
    struct Snode *next;
}Snode,*LinkStack;

bool InitStack(LinkStack &s) {
    s =  NULL;
    return true;
}

bool Push(LinkStack &s,int data) {

    LinkStack p;

    p = (LinkStack) malloc(sizeof(Snode));
    p->data = data;
    p->next = s; //当前节点指向栈顶指针
    s= p;  //修改当前节点为栈顶指针
}

bool Pop(LinkStack &s) {
    LinkStack p;

    if(s == NULL) {  //栈空
        return false;
    }
    p = s;  //当前节点指向栈顶元素
    s= s->next; //栈顶指针指向下一个节点

    printf("出栈：%d\n",p->data);
    delete p; //释放原栈顶元素
    return true;
}

int getTop(LinkStack s) {

    if(s != NULL) {
        return s->data;
    }else {
        return -1;
    }
}

int main() {
    LinkStack  s;
    InitStack(s);
    Push(s,1);
    Push(s,2);
    Push(s,3);
    Push(s,4);
    Push(s,5);

    Pop(s);
    Pop(s);

    int data = getTop(s);
    printf("获取栈顶元素为：%d\n",data);


    return 0;
}
