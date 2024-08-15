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

        ListNode* dummy = new ListNode(INT_MAX, head);
        ListNode* temp = head;
        ListNode* pre = dummy;
        

        while(temp != nullptr){
            bool isHasDuplicate = 0;

            while(temp->next != nullptr && temp->val == temp->next->val){
                temp = temp->next;
                isHasDuplicate = 1;
            }

            if(isHasDuplicate){
                // remove duplicate;
                ListNode* delNode = pre->next;
                while (delNode != temp) {
                    ListNode* nextNode = delNode->next;
                    delete delNode;
                    delNode = nextNode;
                }
                pre->next = temp->next;
                delete temp;  
            }
            else{
                pre = pre->next;
            }

            temp = pre->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
