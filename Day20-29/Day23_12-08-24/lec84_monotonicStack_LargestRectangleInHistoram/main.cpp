#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int areaInTop = 0;
        int maxArea = 0;

        int i = 0;
        while(i < heights.size()){
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i);
                i++;
            }
            else{
                int top = s.top();
                s.pop();

                areaInTop = heights[top] * (s.empty() ? i : i - s.top() - 1);

                if(areaInTop > maxArea){
                    maxArea = areaInTop;
                }
            }
        }

        while(!s.empty()){
            int top = s.top();
            s.pop();

            areaInTop = heights[top] * (s.empty() ? i : i - s.top() - 1);

            if(areaInTop > maxArea){
                maxArea = areaInTop;
            }
        }

        return  maxArea;
    }
};


// Optimize import and export
auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return '$';
}();



int main(){


    return 0;
}