#include <iostream>
#include <vector>
#include <unordered_set> 

using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == nullptr){
            return head;
        }
        
        unordered_set<int> hashTable;

        for(auto x : nums){
            hashTable.insert(x);
        }

        ListNode* temp = head;
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        while(temp != nullptr){
            if(hashTable.find(temp->val) == hashTable.end()){
                if(newHead == nullptr){
                    newHead = new ListNode(temp->val);
                    tail = newHead;
                }
                else{
                    tail->next = new ListNode(temp->val);
                    tail = tail->next;
                }
            }
            temp = temp->next;
        }

        return newHead;
    }
};

// optimize
static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main(){
    return 0;
}