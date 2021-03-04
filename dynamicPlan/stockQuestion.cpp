#include <iostream>

using namespace std;

int getMaxData(int n, int m) {

    return n > m ? n : m;
}

/**
 * 进行一次交易
 * @param prices
 * @param length
 * @return
 */
int buyStockTradeOne(const int prices[], int length) {

    int **dp;
    dp = new int *[length];
    for (int i = 0; i < length; i++) {
        dp[i] = new int[2];
    }

    for (int i = 0; i < length; i++) {
        if (i - 1 == -1) {
            dp[i][0] = 0;
            dp[i][1] = -prices[i];
            continue;
        }
        //今天没有持有：1、昨天没有持有,今天选择休息 2、昨天持有,今天卖掉了
        dp[i][0] = getMaxData(dp[i - 1][0], dp[i - 1][1] + prices[i]);

        //今天持有：1、昨天持有,今天选择休息 2、昨天没有持有,今天买入
        dp[i][1] = getMaxData(dp[i - 1][1], -prices[i]);
    }

    return dp[length - 1][0];
}

/**
 * 进行一次交易迭代版
 * @param prices
 * @param length
 * @return
 */
int buyStockTradeOneDieDai(const int prices[], int length) {

    int dp_i_0 = 0; //dp[-1][0]=0
    int dp_i_1 = INT_MIN; //dp[-1][1] = -infinity

    for (int i = 0; i < length; i++) {

        dp_i_0 = getMaxData(dp_i_0, dp_i_1 + prices[i]);

        dp_i_1 = getMaxData(dp_i_1, -prices[i]);
    }

    return dp_i_0;

}

/**
 * 进行多次交易
 * @param prices
 * @param length
 * @return
 */
int buyStockTrackUnLimit(const int prices[], int length) {

    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;

    for (int i = 0; i < length; i++) {

        int temp = dp_i_0;
        dp_i_0 = getMaxData(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = getMaxData(dp_i_1, temp - prices[i]);
    }

    return dp_i_0;

}

/**
 * 交易新增冷却期,模式变为：买入、卖出、冷却期、买入、卖出
 * @param prices
 * @param length
 * @return
 */
int buyStockTrackCoolOneDay(const int prices[], int length) {

    int temp = 0, dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    int dp_pre_0 = 0; //冷却一天也就是取前两天的利润数据

    for (int i = 0; i < length; i++) {
        temp = dp_i_0;
        dp_i_0 = getMaxData(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = getMaxData(dp_i_1, dp_pre_0 - prices[i]);
        dp_pre_0 = temp; //记录前天的利润
    }

    return dp_i_0;

}

/**
 * 新增每次交易收取费用charge,相当于买入股票的时候股价上涨了,在买入的时候减去费用就好了
 * @param prices
 * @param length
 * @param charge
 * @return
 */
int buyStockTrackServiceCharge(const int prices[], int length, int charge) {

    int temp = 0, dp_i_0 = 0;
    int dp_i_1 = INT_MIN;

    for (int i = 0; i < length; i++) {
        temp = dp_i_0;
        dp_i_0 = getMaxData(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = getMaxData(dp_i_1, temp - prices[i] - charge);
    }

    return dp_i_0;
}


int buyStockTrackTwo(int prices[],int length) {

    int k = 2;
    int ***dp;
    dp = new int **[length];
    for (int i = 0; i < length; i++) {
        dp[i] = new int*[k];
        for (int j = 0; j < k; j++) {
            dp[i][j] = new int[2];
        }
    }

    for (int i = 0; i < length; i++) {
        for (int j = k; j >=1 ; j--) {
            if(i-1 == -1) {
                dp[i][0][0] = 0;
                dp[i][0][1] = -prices[i];
                continue;
            }
            dp[i][k][0] = getMaxData(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
            dp[i][k][1] = getMaxData(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);

        }
    }

    return dp[length-1][k-1][0];


}

/**
 * 购买股票模型,这个问题有三个状态：天数(n)、当天允许交易的最大次数(k)、当前的持有状态(0:表示不持有 1：表示持有)
 * dp[3][2][1]:今天是第三天,我现在手上持有股票,至今最多允许2次交易
 * dp[2][3][0]:今天是第二天,我现在手上没有持有股票,至今最多允许交易3次
 * 我们求的是最后一天(n-1),最多允许交易k次,手上不持有股票(0)的最大利润：dp[n-1][k][0]
 *
 * 状态转移方程
 * case1:今天没有持有股票:1、昨天没有持有股票,今天选择休息 2、昨天有只股票,今天卖掉了(卖掉就加钱)
 *  dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
 * case2:今天持有股票:1、昨天持有股票,今天选择休息 2、昨天没有持有股票,今天选择了购买(购买就得减钱)
 *  dp[i][k][1] = max(dp[i-1][k][1],max[i-1][k-1][0]-prices[i])
 *
 * base case:
 *  dp[-1][k][0] = 0 n是从0开始的,等于-1意味着还没有开始,所以这时候的利润是0
 *  dp[-1][k][1] = -infinity 还没有开始就持有股票,是不可能的,用负无穷表示这种可能
 *  dp[n][0][0] = 0 k是从1开始的,k=0意味着根本不允许交易,所以利润是0
 *  dp[n][0][1] = -infinity 不允许交易的情况下是不允许持有股票的,用负无穷表示这种可能
 *
 * @return
 */
int main() {

    int a[] = {7, 1, 5, 3, 6, 4};
    int length = sizeof(a) / sizeof(int);

    int result = buyStockTradeOne(a, length);
    printf("交易一次的值为：%d\n", result);

    int result1 = buyStockTradeOneDieDai(a, length);
    printf("交易一次的值为：%d\n", result1);

    int result2 = buyStockTrackUnLimit(a, length);
    printf("多次交易的值为：%d\n", result2);

    int b[] = {1, 2, 3, 0, 2};
    int len_b = sizeof(b) / sizeof(int);
    int result3 = buyStockTrackCoolOneDay(b, len_b);
    printf("冷却期交易的值为：%d\n", result3);

    int c[] = {1, 3, 2, 8, 4, 9};
    int len_c = sizeof(c) / sizeof(int);
    int charge = 2;
    int result4 = buyStockTrackServiceCharge(c, len_c, charge);
    printf("存在交易费用的交易值为：%d\n", result4);

    int d[] = {7, 1, 5, 3, 6, 4};
    int len_d = sizeof(d) / sizeof(int);
    int result5 = buyStockTrackTwo(d, len_d);
    printf("只交易两次的值为：%d\n", result5);

    return 0;
}