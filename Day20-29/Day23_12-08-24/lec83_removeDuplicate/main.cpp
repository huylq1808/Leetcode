#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = head;
        ListNode* pre = nullptr;
        int currentValue = INT_MAX;

        while(temp != nullptr){
            if(temp->val != currentValue){
                currentValue = temp->val;
                pre = temp;
                temp = temp->next;
            }
            else{
                ListNode* delNode = temp;
                temp = temp->next;
                
                head = removeNode(head, pre, delNode);
            }
        }

        return head;
    }

    ListNode* removeHead(ListNode* head){
        if(head == nullptr){
            return nullptr;
        }

        ListNode* delNode = head;
        head = head->next;
        
        delete delNode;
        
        return head;
    }

    ListNode* removeNode(ListNode* head, ListNode* previousNode, ListNode* delNode){
        if(delNode == head){
            return removeHead(head);
        }

        previousNode->next = delNode->next;
        delete delNode;

        return head;
    }

    void print(ListNode* head){
        while(head != nullptr){
            cout << head->val << " ";
            head = head->next;
        }
    }
};
 