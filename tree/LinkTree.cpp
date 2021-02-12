#include <stdio.h>
#include <stdlib.h>

typedef struct Bnode {
    char data;
    struct Bnode *lchild,*rchild;
}Bnode,*Btree;


/**
 * 创建二叉树（询问法）
 * @param T
 */
void CreateTreeByAsk(Btree &T) {

    char ch;
    T = new Bnode;
    getchar();
    printf("请输入节点信息:");
    scanf("%c",&T->data);

    printf("是否添加%c的左孩子? (Y/N): ",T->data);

    getchar();
    ch = getchar();

    if(ch == 'Y') {
        CreateTreeByAsk(T->lchild);
    } else {
        T->lchild = NULL;
    }

    printf("是否添加%c的右孩子? (Y/N): ",T->data);

    getchar();
    ch = getchar();
    if(ch == 'Y') {
        CreateTreeByAsk(T->rchild);
    } else {
        T->rchild = NULL;
    }
}


/**
 * 创建二叉树补空法
 * 补空法:如果左子树或者右子树为空时,则用特殊字符补空,如"#",然后按照根、左子树、右子树的顺序得到先序遍历序列,根据该序列递归创建二叉树
 *     1、输入补空后的二叉树先序遍历序列 （ABD##E##CF#G###）
 *     2、如果ch="#" 则T=NULL；否则创建一个新节点T，令T->data=ch；递归创建T的左子树；递归创建T的右子树
 * @param T
 */
void CreateTreeByFillSpace(Btree &T) {
    char ch;
    scanf("%c",&ch);
    if(ch == '#') {
        T = NULL;
    }else {

        T = new Bnode;
        T->data = ch;
        CreateTreeByFillSpace(T->lchild);
        CreateTreeByFillSpace(T->rchild);
    }
}


/**
 * 先序遍历(先跟节点，然后递归遍历左子树，然后递归遍历右子树)
 * @param T
 */
void preOrder(Btree T) {

    if(T) {
        printf("%c",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

/**
 * 中序遍历（递归遍历左子树，根，递归遍历右子树）
 * @param T
 */
void midOrder(Btree T) {

    if(T) {
        midOrder(T->lchild);
        printf("%c",T->data);
        midOrder(T->rchild);
    }
}

/**
 * 后序遍历（递归遍历左子树，递归遍历右子树，根）
 * @param T
 */
void afterOrder(Btree T) {

    if(T) {
        afterOrder(T->lchild);
        afterOrder(T->rchild);
        printf("%c",T->data);
    }
}

int main() {

    Btree T = NULL;
    //CreateTreeByAsk(T); //第一次先回车
    CreateTreeByFillSpace(T); //ABD##E##CF#G###
    printf("先序遍历：");
    preOrder(T);
    printf("\n");

    printf("中序遍历：");
    midOrder(T);
    printf("\n");

    printf("后序遍历：");
    afterOrder(T);
    printf("\n");

    return 0;

}