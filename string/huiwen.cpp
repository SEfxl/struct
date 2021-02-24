#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int num[20];

int coins[] = {1,2,5};
int dp[15];

bool isHuiWen(const char s[],int length) {

    printf("字符序列为: ");
    for (int k = 0; k <length ; ++k) {
        printf("%c ",s[k]);
    }
    printf("\n");

    int i=0,j=length-1;

    bool flag = true;
    while (i<j) {
        printf("i=%d j=%d\n",i,j);
        if(s[i] != s[j]) {
            flag = false;
            break;
        }
        i++;
        j--;
    }

    return flag;
}

void isHuiWenResult() {

    char s[] ={'a','b','b','b','a'};

    int length = sizeof(s);

    printf("length=%d\n",length);
    bool result = isHuiWen(s,length);

    if(result) {
        printf("是回文串\n");
    }else {
        printf("不是回文串\n");
    }
}

int fib(int n) {

    if(n == 1 || n == 2) {
        return 1;
    }

    return fib(n-1) + fib(n-2);

}

void getFibNum(int n) {

    int result = fib(n);
    printf("fib(%d)=%d\n",n,result);

}


int bookFib(int n) {

    if(n == 1 || n == 2) {
        return 1;
    }

    if(num[n] != 0) {
        return num[n];
    }else {
        num[n] = bookFib(n-1)+bookFib(n-2);
        return  num[n];
    }

}

void getBookFibNum(int n) {

    int result = bookFib(n);
    printf("book fib(%d)=%d\n",n,result);
}


int getMin(int m,int n) {

    if(m <n) {
        return  m;
    } else {
        return n;
    }
}

//凑零钱
int coinChange(int amount) {

    //初始化dp数组
    for (int i = 0; i < 15; i++) {
        dp[i] = amount+1;
    }

    dp[0]=0; //base size

    for (int i = 0; i < 15; i++) { //i代表每个盒子的值

        for (int j = 0; j < 3; j++) {

            if(i - coins[j] < 0) {
                continue;
            }

            dp[i] = getMin(dp[i],dp[i-coins[j]]+1);
        }
    }

    return (dp[amount] == amount+1) ? -1 : dp[amount];

}



int main() {

    //isHuiWenResult();
    //getFibNum(10);

    //getBookFibNum(10);

    printf("result= %d\n",coinChange(11));

    return 0;

}