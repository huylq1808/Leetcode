#include <iostream>

using namespace std;


// Definition for a binary tree node.
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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        long long result = 0;
        numOfPath(root, 0, result);

        return int(result);
    }

    void numOfPath(TreeNode* root, int currentSum, long long& result){
        if(root == nullptr){
            return;
        }

        currentSum = currentSum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            result += currentSum;
        }

        if(root->left != nullptr) numOfPath(root->left, currentSum, result);
        if(root->right != nullptr) numOfPath(root->right, currentSum, result);
    }
};

int main(){
    return 0;
}