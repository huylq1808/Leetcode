#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    // using the idea of binary search in array 
    TreeNode* build(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode->left = build(nums, left, mid - 1);
        newNode->right = build(nums, mid + 1, right);

        return newNode;
    }
};

int main(){

    return 0;
}