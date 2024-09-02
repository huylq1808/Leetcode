#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if(s.size() == 1) {
            return 1;
        }        

        int size = s.size();
        shorten(s, size);

        vector<vector<int>> memo(size, vector<int>(size, -1));
        return checking(s, 0, size - 1, memo);        
    }

    int checking(string& s, int left, int right, vector<vector<int>>& memo) {
        if(left > right) {
            return 0; 
        }

        if(memo[left][right] != -1) {
            return memo[left][right];
        }

        int res = checking(s, left + 1, right, memo) + 1;

        for(int i = left + 1; i <= right; i++) {
            if(s[i] == s[left]) {
                res = min(res, checking(s, left, i - 1, memo) + checking(s, i + 1, right, memo));
            }
        }

        memo[left][right] = res;
        return res;
    }

    void shorten(string& s, int& n){
        int sz=s.size();
        n=1;
        // Use 2 pointer to remove successive duplicates
        char cur;
        for(int l=0, r=1; r<sz; r++){
            cur=s[r];
            while(l<r && s[l]==cur) l++;
            if (r<sz && s[l]!=cur){
                s[n++]=s[r];
                l=r;
            }
        }
        s.resize(n);// s is shortened
    }
};

int main(){
    Solution solution;

    string s  = "aaaabbbccda";
    cout << solution.strangePrinter(s);
    cout << s;
    return 0;
}