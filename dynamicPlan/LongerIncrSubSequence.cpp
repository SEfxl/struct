#include <iostream>
using namespace std;
int dp[10];

int getMaxData(int n,int m) {
    return n > m ? n : m;
}

/**
 * 最长递增子序列的长度 （ps:子序列是可以不连续的,子串是连续的）
 * @param nums
 * @param length
 * @return
 */
int getLongerIncrSubSequenceLength(const int nums[],int length) {

    //dp[i] 代表以nums[i]这个数结尾的最长递增子序列的长度

    //base case 每个数字本身的最长递增子序列为1
    for (int i = 0; i < length; ++i) {
        dp[i] = 1;
    }

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < i ; ++j) {

            if(nums[j] < nums[i]) {
                dp[i] = getMaxData(dp[i],dp[j]+1);
            }

        }
    }

    int res = 0;
    for (int k = 0; k < length; ++k) {
        cout<<dp[k]<<" ";
        res = getMaxData(res,dp[k]);
    }

    return res;

}

int main() {

    int a[]= {1,4,3,4,2,3};
    int length = sizeof(a) / sizeof(int);

    int res = getLongerIncrSubSequenceLength(a,length);

    cout<<"最长递增子序列长度为："<<res<<endl;


    return 0;
}