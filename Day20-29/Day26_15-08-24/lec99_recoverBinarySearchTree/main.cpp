#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

// solution for O(n) space: using the tempory array 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> temp;

        traversal(root, temp);

        std::sort(temp.begin(), temp.end());
        int n = 0;
        recover(root, temp, n);
    }

    void traversal(TreeNode* root, vector<int>& arr){
        if(root == nullptr){
            return;
        }

        traversal(root->left, arr);
        arr.push_back(root->val);
        traversal(root->right, arr);
    }

    void recover(TreeNode* root, vector<int>& arr, int& n){
        if(root == nullptr){
            return;
        }

        recover(root->left, arr, n);
        root->val = arr[n++];
        recover(root->right, arr, n);
    }
};

// using morris Inorder traversal 
/*
PSEUDOCODE: 
1. Initialize variables:
- x, y: Pointers to the two nodes that are incorrectly placed.
- pred: Pointer to track the previous node during the inorder traversal.
- predecessor: Pointer to find the inorder predecessor of the current node.
2. Start traversal:

- While root is not null:
    - If root.left exists:
        1 Find the inorder predecessor of root in the left subtree.
        2 If predecessor.right is null (indicating the first visit):
            Set predecessor.right to root to create a temporary link.
            Move root to its left child.
        3 If predecessor.right is already pointing to root (indicating the second visit):
            Break the temporary link by setting predecessor.right to null.
            Check if the current node value is less than the value of pred (the previous node in the traversal):
                If yes, mark y as the current node (root), and if x is not yet set, mark x as pred.
            Set pred to the current node.
            Move root to its right child.
        Else (if root.left does not exist):
            Perform the same check as above to identify nodes x and y.
            Set pred to the current node.
            Move root to its right child.
3. Swap the values of x and y to recover the BST 
*/

//----> in all case we just find one pair of node make the invalid tree 

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr; // Nút tiền nhiệm
        TreeNode* predecessor = nullptr;

        while (root) {
            if (root->left) {
                // Tìm nút tiền nhiệm (predecessor)
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                if (!predecessor->right) {
                    // Thiết lập liên kết từ predecessor đến root
                    predecessor->right = root;
                    root = root->left;
                } else {
                    // Phá vỡ liên kết
                    if (pred && root->val < pred->val) {
                        y = root;
                        if (!x) x = pred;
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                if (pred && root->val < pred->val) {
                    y = root;
                    if (!x) x = pred;
                }
                pred = root;
                root = root->right;
            }
        }

        // Hoán đổi giá trị của x và y để khôi phục cây
        std::swap(x->val, y->val);
    }
};



int main(){
    

    return 0;
}