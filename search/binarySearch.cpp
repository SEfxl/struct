#include <stdlib.h>
#include <stdio.h>

/**
 * 二分查找
 * @param nums
 * @param length
 * @param target
 * @return
 */
int binarySearch(const int nums[], int length, int target) {

    if (length <= 0) {
        return -1;
    }

    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else if (target > nums[mid]) {
            left = mid + 1;
        }
    }

    return -1;
}

int getLeftBoundary(const int nums[], int length, int target) {

    int left = 0;
    int right = length;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (target > nums[mid]) {
            left = mid+1;
        } else if (target < nums[mid]) {
            right = mid;
        }
    }

    if(left == length) {
        return -1;
    }

    return nums[left] == target ? left : -1;

}

int getRightBoundary(const int nums[], int length, int target) {

    int left = 0;
    int right = length;
    while (left < right) {
        int mid = left + (right-left)/2;
        if(nums[mid] == target) {
            left = mid+1;
        }else if(target > nums[mid]){
            left = mid +1;
        }else if(target < nums[mid]) {
            right = mid;
        }
    }

    if(right == 0) {
        return -1;
    }

    return nums[right-1] == target ? right-1 : -1;

}


int main() {

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int index = binarySearch(a, 10, 1);
    if (index == -1) {
        printf("没有找到\n");
    } else {
        printf("index=%d, value=%d\n", index, a[index]);
    }

    int bound[] = {1, 1, 2, 2, 2, 6, 7, 8, 8, 10};
    int leftBoundaryIndex = getLeftBoundary(bound, 10, 10);
    if (leftBoundaryIndex == -1) {
        printf("没有左侧边界\n");
    } else {
        printf("leftBoundIndex=%d\n", leftBoundaryIndex);
    }

    int rightBoundaryIndex = getRightBoundary(bound, 10, 8);
    if (rightBoundaryIndex == -1) {
        printf("没有右侧边界\n");
    } else {
        printf("rightBoundaryIndex=%d\n", rightBoundaryIndex);
    }

    return 0;
}