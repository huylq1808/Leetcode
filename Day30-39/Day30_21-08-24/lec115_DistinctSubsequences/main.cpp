#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // this solution so slow --> must to optimize 
    int numDistinct(string s, string t) {
        if(t.size() > s.size()){
            return 0;
        }

        if(t.size() == s.size() && t == s){
            return 1;
        }

        return checking(s, t, 0, 0);
    }

    int checking(string& s, string& t,int beginPos, int counter){
        if(counter == t.size()){
            return 1;
        }

        int count = 0;

        for(int i = beginPos; i < s.size(); i ++){
            if(s[i] == t[counter]){
                count += checking(s, t, i + 1, counter + 1);
            }
        }

        return count;
    }
};

// another solution using dynamic programming to solve this problem 
class solutionI{
public: 
    int numDistinct(string s, string t) {
        if(t.size() > s.size()){
            return 0;
        }

        if(t.size() == s.size() && t == s){
            return 1;
        }

        int m = s.size();
        int n = t.size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        // init the first column 
        for(int i = 0; i <= m; i++){
            dp[i][0] = 1;
        }

        // fill the table 
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }


};


int main(){

}