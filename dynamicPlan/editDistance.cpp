#include <iostream>

using namespace std;
int dp[10][10];

/**
 * @param n
 * @param m
 * @param p
 * @return
 */
int getMinData(int n, int m, int p) {

    int temp = 0;
    if (n < m) {
        temp = n;
    } else {
        temp = m;
    }

    if (temp < p) {
        return temp;
    } else {
        return p;
    }
}

/**
 * 编辑距离 将s1转化为s2 可以新增、删除、替换 计算需要的操作步骤
 * @param s1
 * @param s1Len
 * @param s2
 * @param s2Len
 * @return
 */
int getEditDistanceMinimum(const char s1[], int s1Len, const char s2[], int s2Len) {

    //base case
    for (int i = 1; i <= s1Len; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= s2Len; j++) {
        dp[0][j] = j;
    }

    //自底向上求解
    for (int i = 1; i <= s1Len; i++) {
        for (int j = 1; j <= s2Len; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = getMinData(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
            }

        }
    }

    return dp[s1Len][s2Len];

}

int main() {

    char s1[] = {'r', 'a', 'd'};
    int s1Len = sizeof(s1);

    char s2[] = {'a', 'p', 'p', 'l', 'e'};
    int s2Len = sizeof(s2);

    cout << "s1Len=" << s1Len << " s2Len=" << s2Len << endl;

    int result = getEditDistanceMinimum(s1, s1Len, s2, s2Len);

    cout << "editDistence=" << result;


    return 0;
}