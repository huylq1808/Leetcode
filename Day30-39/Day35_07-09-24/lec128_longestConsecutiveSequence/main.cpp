#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        set<long long> st;
        int longestLength = 0;

        for(long long x : nums){
            st.insert(x);
        }



        std::set<long long>::iterator it = st.begin();
        long long temp = *it;
        int length = 1;
        for(++it; it != st.end(); ++it){
            if(temp + 1 == *(it)){
                length ++;
            }
            else{
                if(length > longestLength){
                    longestLength = length; 
                }
                length = 1;
            }

            temp = *it;
        }

        if(length > longestLength){
            longestLength = length;
        }

        return longestLength;
    }
};


// optimize 
static const int optimize = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// we can use the radix sort with O(n) time comlexity and then traversal the sorted list to find the result

int main(){

}