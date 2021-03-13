#include <iostream>
using namespace std;

int N;
int W;
int dp[10][10]; //对于当前第i个物品,当前背包容量为w,可以获取的最大价值

int getMaxData(int n, int m) {
    return n > m ? n : m;
}


int getPackageMaxValue(int N,int W, int wt[],int val[]) {

    for (int i = 1; i <= N; i++) { //物品数量
        for (int w = 1; w <= W; w++) { //背包容量

            if(w - wt[i-1] < 0) { //装不下了
                dp[i][w] = dp[i-1][w];
            }else {
                dp[i][w] = getMaxData(dp[i-1][w],dp[i-1][w-wt[i-1]]+val[i-1]);
            }

        }
    }
    return dp[N][W];
}

int main() {

    N = 3;
    W = 4;

    int wt[]={2,1,3}; //物品质量
    int val[] = {4,2,3}; //物品价值

    int value = getPackageMaxValue(N,W,wt,val);
    cout<<"最大价值为："<<value;

    return 0;

}