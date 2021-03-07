#include <stdio.h>


int getMaxNum(int a, int b) {
    return a > b ? a : b;
}

int getMinNum(int a, int b) {
    return a < b ? a : b;
}

/**
 * 暴力获取最大利润:固定了买入时间,穷举了卖出时间
 * @param a
 * @param length
 * @return
 */
int getMaxProfit(const int a[], int length) {

    int res = 0;
    for (int buy = 0; buy < length - 1; buy++) {
        for (int sell = buy + 1; sell < length; sell++) {
            res = getMaxNum(res, a[sell] - a[buy]);
        }
    }

    return res;

}


/**
 * 给定一个数组，它的第i个元素是一支给定股票第i天的价格。如果你最多只允许完成一笔交易(即买入和卖出一支股票)
 * 设计一个算法来获取最大利润
 *
 * 固定卖出时间,穷举买入时间
 * @param a
 * @param length
 * @return
 */
int getMaxProfitV2(const int a[], int length) {

    int res = 0;
    int curMin = a[0];
    for (int sell = 1; sell < length; sell++) {
        curMin = getMinNum(curMin, a[sell]);
        res = getMaxNum(res, a[sell] - curMin);
        //printf("index=%d curMin=%d res=%d\n",sell,curMin,res);
    }
    return res;
}

/**
 * 多次交易获取的最大值
 * @param a
 * @param length
 * @return
 */
int getMaxProfitMoreTrade(const int a[], int length) {

    int profit=0;
    for (int i = 1; i < length; i++) {
        if(a[i] > a[i-1]) {
            profit += a[i] -a[i-1];
        }
    }
    return profit;
}


int main() {

    //int a[] ={7,6,4,3,1};
    int a[] = {7, 1, 5, 3, 6, 4};
    int length = sizeof(a) / sizeof(int);
    int res = getMaxProfit(a, length);
    printf("获取最大价值为：%d\n", res);

    int res2 = getMaxProfitV2(a, length);
    printf("获取最大价值V2：%d\n", res2);

    int res3 = getMaxProfitMoreTrade(a, length);
    printf("多次交易获取的最大价值：%d\n", res3);

    return 0;
}