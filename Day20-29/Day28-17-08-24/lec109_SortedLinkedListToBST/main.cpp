#include <iostream>
#include <vector>

using namespace std;


//  Definition for singly-linked list.
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
    TreeNode* sortedListToBST(ListNode* head) {
        // we using the pre solution to sol 
        vector<int> nums;
        while(head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }

        return build(nums, 0, nums.size() - 1);
    }

    // using the idea of binary search in array 
    TreeNode* build(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode->left = build(nums, left, mid - 1);
        newNode->right = build(nums, mid + 1, right);

        return newNode;
    }
};

int main(){
    

    return 0;
}