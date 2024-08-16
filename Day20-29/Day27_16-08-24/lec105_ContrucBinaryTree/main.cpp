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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;

        return buildTree(inorder, preorder, 0, preorder.size() - 1, preIndex);
    }

    TreeNode* buildTree(vector<int> in, vector<int> pre, int in_start, int in_end, int& preIndex){
        if(in_start > in_end){
            return nullptr;
        }

        TreeNode* node = new TreeNode(pre[preIndex++]);

        int in_index = search(in, in_start, in_end, node->val);

        node->left = buildTree(in, pre, in_start, in_index - 1, preIndex);
        node->right = buildTree(in, pre, in_index + 1, in_end, preIndex);

        return node;
    }

    int search(vector<int> data, int begin, int end, int target){
        for(int i = begin; i <= end; i++){
            if(data[i] == target){
                return i;
            }
        }

        return -1;
    }


};

// we can use stack and set to solve with o(1) search complexity and
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        int j = 0;

        for(int i = 1; i < preorder.size(); i++){
            TreeNode* node = st.top();
            if(node->val != inorder[j]){
                node->left = new TreeNode(preorder[i]);
                st.push(node->left);
            } 
            else{
                // find 
                while(!st.empty() && st.top()->val == inorder[j]){
                    node = st.top();
                    st.pop();
                    j++;
                }
                node->right = new TreeNode(preorder[i]);
                st.push(node->right);
            }
        }
        return root;
    }
};

int main(){

}