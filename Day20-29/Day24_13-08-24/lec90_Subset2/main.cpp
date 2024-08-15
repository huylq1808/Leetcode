#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        
        helper(nums, 0, vector<int>(), result);

        return result;   
    }

    void helper(vector<int>& nums, int left, vector<int> set, vector<vector<int>>& result){
        if(left > nums.size()){
            return;
        }

        result.push_back(set);

        
        for(int i = left; i < nums.size(); i++){
            if(i > left && nums[i] == nums[i - 1]){
                continue;
            }

            set.push_back(nums[i]);

            helper(nums, i + 1, set, result);

            set.pop_back();
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums{1, 2, 2, 3};
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    
    for(int i = 0; i < result.size(); i++){
        cout << i + 1 << " : ";
        for(int x : result[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}