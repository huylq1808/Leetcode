#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength = 0;
        int maxNum = 0;

        for(int x : nums){
            if(maxNum < x){
                maxNum = x;
            }
        }

        int j = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != maxNum){
                j = i;
            }
            maxLength = max(maxLength, i - j);
        }

        return maxLength;
    }
};

int main(){

    return 0;
}