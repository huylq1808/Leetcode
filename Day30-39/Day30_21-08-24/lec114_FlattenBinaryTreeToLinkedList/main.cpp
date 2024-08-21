#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor 
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* leftNode, TreeNode* rightNode) 
        : val(_val), left(leftNode), right(rightNode) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }

        stack<TreeNode*> st;
        st.push(root);
        //

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            if(temp->left != nullptr){
                TreeNode* rightLest = rightLestNode(temp->left);
                rightLest->right = temp->right;
                temp->right = temp->left;
                temp->left = nullptr;
            }
            
            if(temp->right != nullptr)
                st.push(temp->right);
        }
    }

    TreeNode* rightLestNode(TreeNode* root){
        if(root == nullptr || root->right == nullptr){
            return root;
        }

        return rightLestNode(root->right);
    }

};


int main(){


    return 0;
}