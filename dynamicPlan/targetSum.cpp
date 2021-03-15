#include <stdlib.h>
#include <stdio.h>
int N;
int book[10];
int a[10];
int nums;

/**
 * 数的全排列
 * @param step
 */
void dfs(int step) {

    if(step == N+1) {
        for (int i = 1; i <= N ; ++i) {
            printf("%d ",a[i]);
        }

        printf("\n");
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if(book[i] == 0) {
            book[i] = 1;
            a[step] = i;
            dfs(step + 1);
            book[i] = 0;
        }
    }

}

void dfsNum(int step) {

    if(step == N+1) {
        int sum = 0;
        for (int i = 1; i <= N ; ++i) {
            sum+=a[i];
        }

        if(sum == 3) {
            nums++;
        }
        return;
    }

    for (int j = 1; j <=N; ++j) {
        if(book[j] == 0) {
            for (int k = 0; k <=1 ; ++k) {
                book[j] = 1;
                a[step] = k;
                dfsNum(step + 1);
                book[j] = 0;
            }
            //a[step] = j;
            //dfsNum(step + 1);
            //book[j] = 0;
        }
    }

}

int main() {

    N = 4;
    dfs(1);

    //dfsNum(1);
    return 0;
}