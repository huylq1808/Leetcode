#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1]{0};

        dp[0] = dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i - j - 1];
            }
        } 

        return dp[n];
    }
};


int main(){
    Solution solution;
    cout << solution.numTrees(19);

    return 0;
}