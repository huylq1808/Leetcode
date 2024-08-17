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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        if(abs(height(root->left) - height(root->right)) > 1){
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int leftHeight = 1 + height(root->left);
        int rightHeight = 1 + height(root->right);

        return max(leftHeight, rightHeight);
    }
};

int main(){

    return 0;
}