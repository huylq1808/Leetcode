#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> result;
        queue<TreeNode*> q;
        queue<TreeNode*> temp;
        q.push(root);

        while(!temp.empty() || !q.empty()){
            vector<int> set;
            TreeNode* node = nullptr;;
            while(!q.empty()){
                node = q.front();
                q.pop();

                set.push_back(node->val);
                if(node->left != nullptr) temp.push(node->left);
                if(node->right != nullptr) temp.push(node->right);        
            }
            result.push_back(set);
            q = std::move(temp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


int main(){
    
}