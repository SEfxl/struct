#include <stdio.h>
#include <stdlib.h>

int dp[20]; //面值为i时至少需要dp[i]个硬币

int fib(int n) {

    if (n == 1 || n == 2) {
        return 1;
    }

    int pre, cur;
    pre = cur = 1;

    for (int i = 3; i <= n; ++i) {
        int sum = pre + cur;
        pre = cur;
        cur = sum;
    }
    return cur;

}

int getMinData(int n, int m) {
    return n > m ? m : n;
}

/**
 * 凑零钱问题
 * @param amount
 * @param coins
 * @param length
 * @return
 */
int DP(int amount, const int coins[], int length) {

    for (int k = 0; k < 20; ++k) {
        dp[k] = 12; //初始化为一个最大值
    }

    dp[0] = 0;
    for (int i = 0; i <= amount; i++) {

        for (int j = 0; j < length; j++) {

            if (i - coins[j] < 0) { //金额小于硬币面值的时候,直接跳过
                continue;
            }

            //原问题只需要子问题答案+1即可
            dp[i] = 1 + dp[i - coins[j]]; //getMinData(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    return dp[amount];
}

int main() {

    int result = fib(10);
    printf("fib(n)=%d\n", result);


    int conins[] = {1, 2, 5};
    int amount = DP(11, conins, 3);
    printf("数量为：%d\n", amount);

    return 0;
}