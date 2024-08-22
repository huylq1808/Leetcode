#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    // constructor
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return root;
        }

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        Node* temp = nullptr;

        while(!q.empty()){
            Node* pre = nullptr;

            while(!q.empty() && q.front() != nullptr){
                temp = q.front();
                q.pop();

                if(pre != nullptr){
                    pre->next = temp;
                }
                pre = temp;

                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);        
            }
            // remove the nullptr element in queue
            q.pop();

            if(pre != nullptr){ // continue to travel
                pre->next = nullptr;
                q.push(nullptr);
            }
        }

        return root;      
    }
};