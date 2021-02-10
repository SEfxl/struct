#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct SequenceStack {
    int data[MAX_SIZE];
    int top;
}SeqStack;


void InitStask(SeqStack *&s) {

    s = (SeqStack *) malloc(sizeof(SeqStack));
    s->top = -1;
    printf("初始化栈\n");
}

bool push(SeqStack *&s, int data) {

    if(s->top == MAX_SIZE -1) {
        return false;
    }
    s->top++;
    s->data[s->top] = data;
    return  true;
}

bool pop(SeqStack *&s) {

    if(s->top == -1) {
        printf("\n栈为空,跳过");
        return  false;
    }

    printf("出栈:%d\n",s->data[s->top]);
    s->top--;
    return true;
}

void getStackTopData(SeqStack *s) {

    if(s->top == -1) {
        printf("栈为空,跳过\n");
        return ;
    }
    printf("栈顶元素为：%d\n",s->data[s->top]);
}


int main() {
    SeqStack *s;
    InitStask(s);

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);

    pop(s);

    getStackTopData(s);

    return 0;

}
