#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<long long>> dp(n);
        dp[0].push_back(triangle[0][0]);

        for(int i = 1; i < n; i++){
            dp[i] = vector<long long>(i + 1);
            dp[i][0] = triangle[i][0] + dp[i - 1][0];

            for(int j = 1; j < i; j++){
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }

            dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
        }

        int minElement = dp[n - 1][0];

        for(int i = 1; i < n; i++){
            if(minElement > dp[n - 1][i]){
                minElement = dp[n - 1][i];
            }
        }    

        return minElement;
    }

    // another solution optimizer 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=n-2;i>=0;i--)
        {
            int len=triangle[i].size();
            for(int l=0;l<len;l++)
            {
                triangle[i][l]+=min(triangle[i+1][l],triangle[i+1][l+1]);
            }
        }
        return triangle[0][0];
    }
};

int main(){
    Solution solution;

    vector<vector<int>> nums{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << solution.minimumTotal(nums);



    return 0;
}