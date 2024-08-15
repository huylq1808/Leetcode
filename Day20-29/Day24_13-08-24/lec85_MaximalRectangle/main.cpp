#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

class Solution{
public:
    //we will using the solution of the lec84 
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size(), 0);
        int maxArea = 0;
        int currentArea = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j]){
                    dp[j]++;
                }
                else{
                    dp[j] = 0;
                }
            }

            currentArea = largestRectangleArea(dp);
            maxArea = max(maxArea, currentArea);
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int> heights){
        stack<int> s;
        int maxArea = 0;
        int topArea = 0;

        int i = 0;
        while(i < heights.size()){
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i);
                i++;
            }
            else{
                int top = s.top();
                s.pop();

                topArea = heights[top] * (s.empty() ? i : i - s.top() - 1);

                maxArea = max(maxArea, topArea);
            }
        }

        while(!s.empty()){
            int top = s.top();
            s.pop();

            topArea = heights[top] * (s.empty() ? i : i - s.top() - 1);

            maxArea = max(maxArea, topArea);
        }

        return maxArea;
    }
};


int main(){
    Solution solution;

    vector<int> heights{3, 1, 3, 2, 1};

    cout << solution.largestRectangleArea(heights);

    return 0;
}