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
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> result;

        pathSum(root, targetSum, 0, vector<int>(), result);
        
        return result;
    }

    void pathSum(TreeNode* root, int& targetSum,int currentSum, vector<int> set, vector<vector<int>>& result){
        if(root == nullptr){
            return;
        }

        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == currentSum + root->val){
                set.push_back(root->val);
                result.push_back(set);
            }
            
            return;
        }

        set.push_back(root->val);

        pathSum(root->left, targetSum, currentSum + root->val, set, result);
        pathSum(root->right, targetSum, currentSum + root->val, set, result);

        set.pop_back();
    }
};

// Optimized solution using pointers for better performance
// This approach minimizes unnecessary function calls based on the previous solution

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> result;
        int currentSum = 0;
        vector<int> set;

        pathSum(root, targetSum, currentSum, set, result);
        
        return result;
    }

    void pathSum(TreeNode* root, int& targetSum, int& currentSum, vector<int>& set, vector<vector<int>>& result){
        if(root == nullptr){
            return;
        }

        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == currentSum + root->val){
                set.push_back(root->val);
                result.push_back(set);
                set.pop_back();
            }
            
            return;
        }

        set.push_back(root->val);
        currentSum += root->val;

        if(root->left != nullptr)
            pathSum(root->left, targetSum, currentSum, set, result);
        if(root->right != nullptr)
            pathSum(root->right, targetSum, currentSum, set, result);

        currentSum -= root->val;
        set.pop_back();
    }
};


int main(){


    return 0;
}