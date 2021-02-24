#include <stdlib.h>
#include <stdio.h>

int binarySearch(const int nums[],int length,int target) {

    if(length <=0) {
        return  -1;
    }

    int left = 0;
    int right = length-1;

    while (left <= right) {
        int mid = left + (right-left)/2;
        if(nums[mid] == target) {
            return mid;
        } else if(target < nums[mid]) {
            right = mid -1;
        }else if(target > nums[mid]) {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {

    int a[]= {1,2,3,4,5,6,7,8,9,10};

    int index = binarySearch(a,10,1);

    if(index == -1) {
        printf("没有找到\n");
    } else {
        printf("index=%d, value=%d\n",index,a[index]);
    }

    return 0;
}