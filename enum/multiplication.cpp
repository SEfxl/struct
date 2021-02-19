#include <stdio.h>
#include <stdlib.h>


#define MAX 10

/**
  * 题目:abc + def = ghi
 *  a~i = 1~9
 */
int main() {

    printf("here\n");

    int a[MAX],book[MAX],sum=0,total=0;

    for (a[1] = 0; a[1]<= 9; a[1]++) {
        for (a[2] = 1; a[2] <=9 ; a[2]++) {
            for (a[3] = 1; a[3] <=9 ; a[3]++) {
                for (a[4] = 1; a[4] <=9 ; a[4]++) {
                    for (a[5] = 1; a[5] <=9 ; a[5]++) {
                        for (a[6] = 1; a[6] <=9 ; a[6]++) {
                            for (a[7] = 1; a[7] <=9 ; a[7]++) {
                                for (a[8] = 1; a[8] <=9 ; a[8]++) {
                                    for (a[9] = 1; a[9] <=9 ; a[9]++) {

                                        for (int i = 1; i <= 9; ++i) { //初始化
                                            book[i] = 0;
                                        }

                                        for (int j = 1; j <= 9 ; j++) { //标记已经访问过
                                            book[a[j]] = 1;
                                        }

                                        sum = 0;
                                        for (int k = 1; k <=9 ; k++) {
                                            sum += book[k];
                                        }

                                        if(sum == 9 && a[1]*100+a[2]*10+a[3] + a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9]) {
                                            total++;
                                            printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    printf("\ntotal=%d\n",total);

    return 0;

}