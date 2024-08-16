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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) { // base case 
            return {}; 
        }
        
        vector<vector<int>> zig;  
        bool flip = false; 
        
        queue<TreeNode*> queue;
        queue.push(root); 
        
        while(!queue.empty()) {
            vector<int> zag; 
            int node_count = queue.size(); 
            
            // push Node to list and get data to zag 
            for (int i = 0; i < node_count; i++) {
                TreeNode* curr = queue.front(); 
                queue.pop(); 
                
                zag.push_back(curr->val); 
                
                if (curr->left != nullptr) {
                    queue.push(curr->left); 
                }
                
                if (curr->right != nullptr) {
                    queue.push(curr->right); 
                }
            }
            
            // reverse the list
            if (flip) {
                reverse(zag.begin(), zag.end()); 
            }
            
            zig.push_back(zag); 
            
            flip = !flip; 
        
        }
        
        return zig; 
    }
};