#include <iostream>
#include <vector>
using namespace std;


void getNoCrossIntervalNum() {

    int intvs[3][2] = {{1,4},{2,8},{3,6}};

    int left = intvs[0][0];
    int right = intvs[0][1];
    int intv[2] ={0,0};
    int res = 0;


    for (int i = 1; i <3 ; i++) {
        intv[0] = intvs[i][0];
        intv[1] = intvs[i][1];

        //覆盖区间
        if(left <= intv[0] && right >= intv[1]) {
            res++;
        }

        //相交区间
        if(right >= intv[0] && right <= intv[1]) {
            right = intv[1];
        }
        //printf("--> left=%d right=%d intv[0]=%d intv[1]=%d\n",left,right,intv[0],intv[1]);
        //完全不相交
        if(right < intv[0]) {
            left = intv[0];
            right = intv[1];
        }
        //printf("----> left=%d right=%d intv[0]=%d intv[1]=%d\n",left,right,intv[0],intv[1]);

    }

    printf("覆盖区间为：%d\n",res);

}

int main() {

    getNoCrossIntervalNum();
    return 0;
}