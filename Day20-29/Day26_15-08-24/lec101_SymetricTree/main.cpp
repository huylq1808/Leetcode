#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    // property 
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        queue<TreeNode*> left;
        queue<TreeNode*> right;

        left.push(root->left);
        right.push(root->right);

        TreeNode* rightTemp;
        TreeNode* leftTemp;
         
        while(!left.empty() && !right.empty()){
            leftTemp = left.front();
            rightTemp = right.front();
            left.pop();
            right.pop();

            if(leftTemp == nullptr && rightTemp == nullptr){
                continue;
            }

            if(leftTemp == nullptr || rightTemp == nullptr || leftTemp->val != rightTemp->val){
                return false;
            }

            left.push(leftTemp->right);
            left.push(leftTemp->left);

            right.push(rightTemp->left);
            right.push(rightTemp->right);
        }

        if(!left.empty() || !right.empty()){
            return false;
        }

        return true;
    }
};


int main(){

    return 0;
}