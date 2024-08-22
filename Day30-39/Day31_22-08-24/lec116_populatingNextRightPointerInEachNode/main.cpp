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
        if(root == nullptr || root->left == nullptr){
            return root;
        }

        queue<Node*> q;
        q.push(root->left);
        q.push(root->right);

        int step = 2;
        Node* temp = nullptr;

        while(!q.empty()){
            Node* pre = nullptr;

            for(int i = 0; i < step; i++){
                temp = q.front();
                q.pop();
                
                if(pre != nullptr){
                    pre->next = temp;
                }
                pre = temp;

                // insert to queue 
                if(temp->left != nullptr){
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }

            if(pre != nullptr){
                pre->next = nullptr;
            }

            step *= 2;
        }

        return root;
    }
};

// another solution -MAGIC- 
class Solution {
public:
    Node* connect(Node* root, Node* par = NULL) {
        if (!root || !root->left) 
            return root;

        cout << "inside: " << root->val << endl;

        root->left->next = root->right;
        if (!root->next && par && par->next)
            root->next = par->next->left;

        connect(root->left, root);
        connect(root->right, root);

        /*if (root->left->left) {
            root->left->right->next = root->right->left;
        }*/

        if (root->next)
            root->right->next = root->next->left;

        

        return root;
    }
};

int main(){
    return 0;
}