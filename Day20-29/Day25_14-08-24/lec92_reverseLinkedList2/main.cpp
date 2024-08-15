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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        int counter = 1;
        ListNode* dummy = new ListNode(INT_MAX, head);
        ListNode* pre = dummy;

        while(counter < left){
            pre = pre->next;
            counter++;
        }
        
        ListNode* pivot = pre;
        ListNode* temp = pre->next;
        ListNode* next = temp->next;

        while(counter <= right){
            temp->next = pre;
            pre = temp;
            temp = next;

            if(next == nullptr){
                break;
            }
            next = next->next;

            counter++;
        }

        pivot->next->next = temp;
        pivot->next = pre;

        delete dummy;

        if(left == 1){
            return pre;
        }

        return head;
    }
};
int main(){
    


    return 0;
}