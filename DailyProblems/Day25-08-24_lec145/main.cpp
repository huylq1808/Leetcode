#include <iostream>
#include <vector>
#include <stack>

using namespace std;


 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

// solution using recursion 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<int> result;

        postOrder(root, result);
        
        return result;
    }

    void postOrder(TreeNode* root, vector<int>& result){
        if(root == nullptr){
            return;
        }

        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }
};

// another solution using stack 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<int> result;

        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;
        TreeNode* current = root;

        while(!st.empty() || current != nullptr){
            if(current != nullptr){
                //travel to the lasted of left 
                st.push(current);
                current = current->left;
            }
            else{
                // if the left node is null but have left node 
                TreeNode* node = st.top();
                
                if(node->right != nullptr && lastVisited != node->right){
                    current = node->right;
                }
                else{
                    // is the value to insert 
                    result.push_back(node->val);
                    st.pop();
                    lastVisited = node;
                }
            }
        }

        return result;
    }
};

int main(){


    return 0;
}