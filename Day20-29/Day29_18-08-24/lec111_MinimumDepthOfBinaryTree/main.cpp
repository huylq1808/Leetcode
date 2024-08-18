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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if(leftDepth == 0){
            return rightDepth + 1;
        }
        else if(rightDepth == 0){
            return leftDepth + 1;
        }

        return 1 + min(leftDepth, rightDepth );
    }
};


int main(){

    return 0;
}