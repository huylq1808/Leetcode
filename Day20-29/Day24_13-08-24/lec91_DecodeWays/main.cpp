#include <iostream>
#include <string>
#include <set>

using namespace std;

const int MaxSize = 100;
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }


        int dp[MaxSize + 1];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= s.size(); i++){
            dp[i] = 0;

            if(s[i - 1] > '0'){// the current pivot is zero 
                dp[i] = dp[i - 1];
            }

            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')){{
                dp[i] += dp[i - 2];
            }}
        } 

        return dp[s.size()]; 
    }
};

int main(){

}