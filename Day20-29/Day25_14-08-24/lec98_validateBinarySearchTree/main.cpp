#include <iostream>

using namespace std;

 //* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        TreeNode* minNode = findMinNode(root->right);
        TreeNode* maxNode = findMaxNode(root->left);

        if ((minNode != nullptr && root->val >= minNode->val) || 
        (maxNode != nullptr && root->val <= maxNode->val)) {
            return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }

    TreeNode* findMinNode(TreeNode* root){
        if(root == nullptr || root->left == nullptr){
            return root;
        }

        return findMinNode(root->left);
    }

    TreeNode* findMaxNode(TreeNode* root){
        if(root == nullptr || root->right == nullptr){
            return root;
        }

        return findMaxNode(root->right);
    }
};

int main(){
    
}