#include <iostream>

using namespace std;

int result = 0;
int res[10]; //记录做的选择

void calculate(int nums[], int length, int i, int target) {
    if (length == i) {
        if(target == 0) {
            for (int j = 0; j < length; ++j) {
                printf("%d ",res[j]);
            }
            printf("\n");
            result++;
        }
        return;
    }

    //给nums[i] 选择 - 号
    target += nums[i];
    res[i] = nums[i];
    //穷举nums[i+1]
    calculate(nums,length,i+1,target);
    //撤销选择
    target -= nums[i];

    //给nums[i] 选择 + 号
    target -= nums[i];
    res[i] = -nums[i];
    calculate(nums,length,i+1,target);
    target += nums[i];


}

/**
 * 给定一个整数数组和一个目标值,在整数前面输入+-使其正好等于目标值
 * @param nums
 * @param length
 * @param target
 * @return
 */
int findTargetSum(int nums[], int length, int target) {

    calculate(nums, length, 0, target);

}

int main() {

    int a[]= {1,1,1,1,1};
    findTargetSum(a,5,3);

    printf("result=%d\n",result);


    return 0;
}