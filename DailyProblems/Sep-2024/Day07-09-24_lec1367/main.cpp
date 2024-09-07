#include <iostream>
#include <queue> 
using namespace std; 


// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == nullptr || root == nullptr){
            return false;
        }

        bool isFound = false;
        if(root->val == head->val){
            isFound = checkSubPath(head, root); 
        }

        return isFound || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool checkSubPath(ListNode* head, TreeNode* root){
        if(head == nullptr){
            return true;
        }

        if((root == nullptr && head != nullptr) || root->val != head->val){
            return false;
        }

        return checkSubPath(head->next, root->left) || checkSubPath(head->next, root->right); 
    }
};