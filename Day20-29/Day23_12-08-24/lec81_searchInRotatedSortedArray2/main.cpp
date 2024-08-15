#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while(left <= right){
            mid = left + (right - left) / 2;

            if(nums[mid] == target){
                return true;
            }
            

            // if can't find the sorted sub array
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } 
            else if (nums[left] <= nums[mid]) {  //left sub array is sorted 
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } 
                else {
                    left = mid + 1;
                }
            } 
            else {  // right sub array is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } 
                else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main(){


    return 0;
}