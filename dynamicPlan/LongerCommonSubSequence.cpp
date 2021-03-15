#include <iostream>
using namespace std;
int dp[10][10];

int getMaxData(int n,int m) {
    return n > m ? n : m;
}

/**
 * 最长公共子序列
 * @param s1
 * @param s1Len
 * @param s2
 * @param s2Len
 * @return
 */
int getLongerCommonSubSequence(const char s1[], int s1Len,const char s2[],int s2Len) {

    if(s1Len <=0 || s2Len <= 0) {
        return 0;
    }

    //base case [..][0] [0][...]的值都是0,我们从1开始遍历字符数组

    for (int i = 1; i <= s1Len ; i++) {
        for (int j = 1; j <= s2Len; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = getMaxData(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[s1Len][s2Len];
}

int main() {


    char s1[] ={'0','a','b','c','d','e'};
    int s1Len = sizeof(s1);

    char s2[] ={'0','a','c','e'};
    int s2Len = sizeof(s2);

    int result = getLongerCommonSubSequence(s1,s1Len,s2,s2Len);
    cout<<"最长公共子序列长度为："<<result<<endl;


    return 0;
}