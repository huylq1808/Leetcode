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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        if(n == 0 || m == 0){
            return {};
        }      

        vector<vector<int>> result(m, vector<int>(n, -1));

        for(int count = 0; count < m / 2 + 1 && head != nullptr; ++count){
            //fill the top 
            for(int i = count; i < n - count && head != nullptr; i++){
                result[count][i] = head->val;
                head = head->next;
            }

            if(head == nullptr){
                break;
            }

            // fill the right 
            for(int i = count + 1; i < m - count - 1 && head != nullptr; i++){
                result[i][n - count - 1] = head->val;
                head = head->next;
            }

            // fill the bottom 
            for(int i = n - count - 1; i >= count && head != nullptr; i--){
                result[m - count - 1][i] = head->val;
                head = head->next;
            }


            // fill the left 
            for(int i = m - count - 2; i > count && head != nullptr; i--){
                result[i][count] = head->val;
                head = head->next;
            }
        }

        return result;
    }
};

int main(){
    

    return 0;
}