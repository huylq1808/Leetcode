#include <iostream>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(root, targetSum, 0);
    }

    bool hasPathSum(TreeNode* root, int& target, int currentSum){
        if(root == nullptr){
            return false;
        }

        if(root->left == nullptr && root->right == nullptr){
            return target == (currentSum + root->val);
        }


        return hasPathSum(root->left, target, currentSum + root->val)
            || hasPathSum(root->right, target, currentSum + root->val);
    }
};

int main(){

}