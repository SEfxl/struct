#include <stdio.h>
#include <stdlib.h>
int book[10],a[10];
int number;


void dfs(int step) {

    if(step == number+1) { //此时找到一组全排列组合
        for (int i = 1; i <= number ; i++) {
            printf("%d ",a[i]);
        }
        printf("\n");
        return ;
    }


    for (int i = 1; i <= number; i++) {

        if(book[i] == 0) {
            a[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }

}


int main() {

    scanf("%d",&number);
    dfs(1);
    return 0;
}