#include <iostream>
#include <vector>
#include <stack>

using namespace std;

 // Definition for a binary tree node.
struct TreeNode {
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = postorder.size() - 1;
        TreeNode* root = new TreeNode(postorder[len]);
        stack<TreeNode*> st;
        st.push(root);
        int j = len;

        for(int i = len - 1; i >= 0; i--){
            TreeNode* node = st.top();

            if(node->val != inorder[j]){
                node->right = new TreeNode(postorder[i]);
                st.push(node->right);
            }
            else{
                while(!st.empty() && st.top()->val == inorder[j]){
                    node = st.top();
                    st.pop();
                    j--;
                }
                node->left = new TreeNode(postorder[i]);
                st.push(node->left);
            }
        }

        return root;
    }
};



int main(){


    return 0;
}