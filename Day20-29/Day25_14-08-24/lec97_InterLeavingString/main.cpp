#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int firstPivot = 0;
        int n = s1.size();
        int secondPivot = 0;
        int m = s2.size();
        vector<int> duplicatePivot;

        for(int i = 0; i < s3.size(); i++){
            if(firstPivot < n && s3[i] == s1[firstPivot]){
                if(secondPivot < m && s2[secondPivot] == s3[i]){
                    return (isInterleave(s1.substr(firstPivot + 1), s2.substr(secondPivot), s3.substr(i + 1)) 
                        || isInterleave(s1.substr(firstPivot), s2.substr(secondPivot + 1), s3.substr(i + 1)));
                }
                
                firstPivot++;
                continue;
            }

            if(secondPivot < m && s3[i] == s2[secondPivot]){
                secondPivot++;
                continue;
            }
            
            return false;
        }

        return true;
    }
};

// optimize solution using dp 
bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size();
    int m = s2.size();
    int k = s3.size();
    
    // If the size of s3 is not equal to the sum of s1 and s2, return false
    if (k != n + m) {
        return false;
    }

    // Create a 1D DP array with size m + 1
    vector<bool> dp(m + 1, false);
    
    // Initialize the DP array
    dp[0] = true;
    
    // Fill the first row of DP array (when s1 is empty)
    for (int j = 1; j <= m; j++) {
        dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
    }
    
    // Iterate over each character in s1
    for (int i = 1; i <= n; i++) {
        // Update the first element of DP array for each new row (when s2 is empty)
        dp[0] = dp[0] && s1[i-1] == s3[i-1];
        
        // Fill the DP array for the current row
        for (int j = 1; j <= m; j++) {
            dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    
    // The result is stored in the last cell of the DP array
    return dp[m];
}

int main(){
    Solution solution;

    if(solution.isInterleave("aabcc", "dbbca", "aadbbcbcac")){
        cout << "TRUE\n";
    }
    else{
        cout << "FALSE\n";
    }

    return 0;
}