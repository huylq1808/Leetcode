#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, bool> dp;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()){
            return false;
        }

        if(s1 == s2){
            return true;
        }

        string copyS1 = s1;
        string copyS2 = s2;

        std::sort(copyS1.begin(), copyS1.end());
        std::sort(copyS2.begin(), copyS2.end());

        if(copyS1 != copyS2){
            return false;
        }

        string key = s1 + " " + s2;
        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        bool flag = false;
        int n = s1.size();

        for(int i = 1; i < n; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i))){
                flag = true;
                break;
            }

            if(isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i))){ // Sửa điều kiện
                flag = true;
                break;
            }
        }

        dp[key] = flag;

        return flag;
    }
};

int main(){


    return 0;
}