#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int width = points[0].size();
        long long maxPoint = 0;
        vector<long long> current(width), pre(width);
        for(vector<int>& level : points){
            long long peak = 0;

            for(int i = 0; i < width; i++){
                peak = max(peak - 1, pre[i]);
                current[i] = peak;
            }

            peak = 0;

            for(int i = width - 1; i >= 0; i--){
                peak = max(peak - 1, pre[i]);
                current[i] = max(current[i], peak) + level[i];
            }

            pre.swap(current);
        }

        maxPoint = *max_element(pre.begin(), pre.end());

        return maxPoint;
    }
};

// optimize import and export 
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();