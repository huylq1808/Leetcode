#include <iostream>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string convertStr = "";

        for(char x : s){
            int num = x - 'a' + 1;
            convertStr += to_string(num);
        }      

        return tranform(convertStr, k);
    }

    int tranform(string s, int k){
        if(k == 0 || s.size() <= 1){
            return stoi(s);
        }

        int sum = 0;
        for(char x : s){
            sum += x - '0';
        }

        return tranform(to_string(sum), k - 1);
    }
};

int main(){
    Solution solution;

    cout << solution.getLucky("leetcode", 2);
    return 0;
}