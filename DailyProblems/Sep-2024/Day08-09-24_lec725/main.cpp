#include <iostream>
#include <vector>

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = size(head);

        vector<ListNode*> result(k);

        int m = n / k;
        int temp = n % k;
        ListNode* curr = head;
    
        for (int i = 0; i < k; i++) {
            ListNode* partHead = curr;
            int partSize = m + (temp > 0 ? 1 : 0); // size of part 

            if (curr) {
                // find the tail of part 
                for (int j = 1; j < partSize; j++) {
                    if (curr) curr = curr->next;
                }

                // set the new cur 
                if (curr) {
                    ListNode* nextPart = curr->next;
                    curr->next = nullptr;
                    curr = nextPart;
                }
            }

            //push the part into the result 
            result[i] = partHead;
            temp--;
        }

        return result;
    }

    int size(const ListNode* head){
        int count = 0;
        while(head != nullptr){
            count++;
            head = head->next;
        }

        return count;
    }
};

int main(){


    return 0;
}