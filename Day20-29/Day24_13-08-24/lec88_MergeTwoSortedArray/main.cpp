#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return;
        }

        for(int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }

        std::sort(nums1.begin(), nums1.end());
    }
};

int main(){

    return 0;
}