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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        //find the node have value greater than or equal to x 
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        while(pre->next != nullptr && pre->next->val < x){
            pre = pre->next;
        }

        // set the tempHead to the pivot 
        ListNode* temp = pre->next;
        ListNode* preOfTemp = pre;
        while(temp != nullptr){
            if(temp->val < x){
                //found the value need to partition 
                ListNode* partitionNode = temp;
                preOfTemp->next = temp->next;
                temp = temp->next;

                // put the partition node right to pre
                partitionNode->next = pre->next;
                pre->next = partitionNode;
                pre = pre->next;
            }
            else{
                preOfTemp = temp;
                temp = temp->next;
            }
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};

int main(){

    return 0;
}