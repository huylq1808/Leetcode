#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor 
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {} 
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) 
        : val(_val), left(_left), right(_right) {} 
};

class Solution{
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int result = INT_MIN;

        maxPathSum(root, result);

        return result;
    }

    int maxPathSum(TreeNode* root, int& res){
        if(root == nullptr){
            return 0;
        }

        int lef = maxPathSum(root->left, res);
        int rig = maxPathSum(root->right, res);

        // the path is the root or the sub path of left or right subtree 
        int maxSingle = max(max(lef, rig) + root->val, root->val);

        // the path is  the sum of node and subtree or the maxSingle 
        int maxTop = max(maxSingle, lef + rig + root->val);

        res = max(res, maxTop);

        return maxSingle;
    }
};

int main(){


    return 0;
}