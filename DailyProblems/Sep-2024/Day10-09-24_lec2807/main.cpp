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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = head;
        while(temp->next != nullptr){
            int divisor = findGreatestCommondDivisor(temp->val, temp->next->val);

            // insert into linked list
            temp = insert(temp, divisor);
        
            temp = temp->next->next;
        }

        return head;
    }

    int findGreatestCommondDivisor(int x, int y){
        if(y == 0){
            return x;
        }

        return findGreatestCommondDivisor(y, x % y);
    }

    ListNode* insert(ListNode* head, int val){
        if(head == nullptr){
            return nullptr;
        }

        ListNode* newNode = new ListNode(val, head->next);
        head->next = newNode;

        return head;
    }
};


int main(){
    return 0;
}