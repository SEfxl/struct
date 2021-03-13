#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target) {
    sort(nums.begin(),nums.end());
    int low = 0;
    int high = nums.size()-1;

    vector<int> res;

    while (low < high) {
        int sum = nums[low] + nums[high];
        if(sum < target) {
            low++;
        }else if(sum > target) {
            high--;
        } else if(sum == target) {
            res.push_back(nums[low]);
            res.push_back(nums[high]);
            return res;

        }
    }

    return res;

}

int main() {

    return 0;
}