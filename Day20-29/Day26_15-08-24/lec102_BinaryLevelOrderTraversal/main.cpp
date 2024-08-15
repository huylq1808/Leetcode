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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return vector<vector<int>>();
        }

        vector<vector<int>> result;
        queue<TreeNode*> header;
        queue<TreeNode*> temp;

        header.push(root);
        
        // calling function 
        helper(header, temp, result);

        return result;
    }

    void helper(queue<TreeNode*>& headerQueue, queue<TreeNode*>& tempQueue, vector<vector<int>>& result){
        if(headerQueue.empty()){
            return;
        }

        TreeNode* temp = nullptr;
        vector<int> set;
        while(!headerQueue.empty()){
            temp = headerQueue.front();
            headerQueue.pop();

            if(temp != nullptr){
                set.push_back(temp->val);
                tempQueue.push(temp->left);
                tempQueue.push(temp->right);
            }
        }

        if(!set.empty()){
            result.push_back(set);
        }
        
        helper(tempQueue, headerQueue, result);
    }
};