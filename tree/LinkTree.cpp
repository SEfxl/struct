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


/**
 * 计算以T的树有多少节点
 * @param T
 * @return
 */
int treeCount(Btree T) {

    if(T==NULL) {
        return 0;
    }

    return 1 + treeCount(T->lchild) + treeCount(T->rchild);

}

/**
 * 将树以跟节点为竖线,作为镜子进行映射（先序遍历序列）
 * @param T
 */
void treeMirrorPreOrder(Btree &T) {

    if(T == NULL) {
        return;
    }

    //交换当前节点的左右子节点
    Btree temp;
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;

    //让左右子节点继续交换他们的子节点
    treeMirrorPreOrder(T->lchild);
    treeMirrorPreOrder(T->rchild);
}

/**
 * 将树以跟节点为竖线,作为镜子进行映射（后序遍历序列）
 * @param T
 */
void treeMirrorAfterOrder(Btree &T) {

    if(T == NULL) {
        return;
    }

    treeMirrorAfterOrder(T->lchild);
    treeMirrorAfterOrder(T->rchild);

    Btree temp;
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;

}



/**
 * 构建最大二叉树
 * @param nums
 * @param low
 * @param high
 * @return
 */
Btree build(int *nums,int low,int high) {

    if(low > high) {
        return NULL;
    }

    int index = -1;
    int maxValue = -100;
    for (int i = low; i <= high ; i++) {
        if(maxValue < nums[i]) {
            index = i;
            maxValue = nums[i];
        }
    }

    Btree root;
    root = new Bnode;
    root->data = (char)maxValue;

    root->lchild = build(nums,low,index-1);
    root->rchild = build(nums,index+1,high);

    return root;

}

/**
 * 构建最大二叉树
 *
 * @param nums
 * @return
 */
Btree constructMaximumBinaryTree(int nums[]) {
    return build(nums,0,5);
}




Btree buildTree(int *preOrder,int preStart,int preEnd, int *midOrder, int inStart, int inEnd) {

    if(preStart > preEnd) {
        return NULL;
    }

    int rootVal = preOrder[preStart]; //根节点

    int index = -1;  //根节点在后续遍历数组中的下标
    for (int i = 0; i <= inEnd; i++) {
        if(rootVal == midOrder[i]) {
            index = i;
            break;
        }
    }

    int leftSize = index - inStart;

    Btree root;
    root = new Bnode;
    root->data = (char)rootVal;

    root->lchild = buildTree(preOrder,preStart+1,preStart+leftSize,midOrder,inStart,index-1);

    root->rchild = buildTree(preOrder,preStart+leftSize+1,preEnd,midOrder,index+1,inEnd);

    return root;

}

/**
 * 根据前序和中序序列构建二叉树
 * @param preOrder
 * @param preLength
 * @param midOrder
 * @param midLength
 * @return
 */
Btree constructNewTree(int preOrder[],int preLength,int midOrder[], int midLength) {

    return buildTree(preOrder,0,preLength-1,midOrder,0,midLength-1);

}


int main() {

    /*
    Btree T = NULL;
    //CreateTreeByAsk(T); //第一次先回车
    CreateTreeByFillSpace(T); //ABD##E##CF#G###  421##3##76##9##
    printf("先序遍历：");
    preOrder(T);
    printf("\n");

    printf("中序遍历：");
    midOrder(T);
    printf("\n");

    printf("后序遍历：");
    afterOrder(T);
    printf("\n");

    printf("节点数为：%d\n",treeCount(T));

    treeMirrorPreOrder(T);
    printf("先序遍历反转：");
    preOrder(T);
    printf("\n");

    treeMirrorAfterOrder(T);
    printf("后序遍历反转：");
    preOrder(T);
    printf("\n");
    */

    //
//    int arr[] = {3,2,1,6,0,5};
//    Btree root = constructMaximumBinaryTree(arr);
//    printf("先序遍历：");
//    preOrder(root);
//    printf("\n");



    int preOrderArr[]= {1,2,5,4,6,7,3,8,9};
    int midOrderArr[]= {5,2,6,4,7,1,8,3,9};
    Btree root2 = constructNewTree(preOrderArr,9,midOrderArr,9);
    printf("先序遍历：");
    preOrder(root2);
    printf("\n");

    return 0;

}