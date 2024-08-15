#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        helper(nums, result, vector<int>(), 0);

        return result;
    }

    void helper(vector<int> nums, vector<vector<int>>& result, vector<int> sets, int position){
        result.push_back(sets);

        for(int i = position ; i < nums.size(); i++){
            sets.push_back(nums[i]);

            helper(nums, result, sets, i + 1);

            sets.pop_back();;
        }
    }
};

// we can using bit manibunation to solve this problem 
// Function to find the subsets of the given array
void findSubsets(int nums[], int n)
{
    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add the jth element to the subset
                cout << nums[j] << " ";
            }
        }

        cout << endl;
    }
}


int main(){


    return 0;
}