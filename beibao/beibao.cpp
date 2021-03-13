#include <iostream>
#include <vector>

using namespace std;
int dp[4][5];

int getMaxMoney(int N, int W, int wt[], int val[]) {

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[i] < 0) { //装不下
                dp[i][w] = dp[i - 1][w]; //装不下只能选择不装,继承之前的状态
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i-1]] + val[i - 1]); //装的下就需要看剩余容量能装的下的最大价值
            }
        }
    }

    return dp[N][N];

}

int main() {

    int wt[] = {2, 1, 3};
    int val[] = {4, 2, 3};
    int res = getMaxMoney(3, 4, wt, val);
    printf("最大值:%d", res);

    return 0;
}