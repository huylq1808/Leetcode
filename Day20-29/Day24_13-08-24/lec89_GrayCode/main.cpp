#include <iostream>
#include <vector>
#include <queue> 
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int num_codes = 1 << n; // 2^n

        for (int i = 0; i < num_codes; i++) {
            result.push_back(i ^ (i >> 1)); // công thức của gray code 
        }

        return result;
    }
};

// another solution 
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> ans{0};

    for (int i = 0; i < n; ++i)
      for (int j = ans.size() - 1; j >= 0; --j)
        ans.push_back(ans[j] | 1 << i);

    return ans;
  }
};

int main(){
    Solution solution;

    vector<int> result = solution.grayCode(3);

    for(auto x : result){
        cout << x << endl;
    }

    return 0;
}