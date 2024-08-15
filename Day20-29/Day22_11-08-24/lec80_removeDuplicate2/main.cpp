#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 1;
        int exist = 0;

        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] == nums[i - 1]){
                if(exist){
                    continue;
                }

                nums[counter] = nums[i];
                counter++;
                exist = 1;
            }
            else{
                nums[counter] = nums[i];
                counter++;
                exist = 0;
            }
        }

        return counter;
    }
};

int main(){
    

    return 0;
}