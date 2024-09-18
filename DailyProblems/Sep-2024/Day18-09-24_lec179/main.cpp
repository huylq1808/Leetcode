#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // sort using the customize compare function 
        std::sort(nums.begin(), nums.end(), compare);

        //if the first element is '0' --> all element is 0
        if(nums[0] == 0){
            return "0";
        }  

        string result;
        for(int x : nums){
            result += to_string(x);
        }

        return result;
    }

    bool compare(int num1, int num2){
        string s1 = to_string(num1) + to_string(num2);
        string s2 = to_string(num2) + to_string(num1);
        
        return s1 > s2;
    }
};

static const int optimize = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main(){
    Solution solution;
    return 0;
}