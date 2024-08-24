#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


class Solution{
public:
    string nearestPalindromic(string n){
        vector<long long> candidates;
        int len = n.length();

        int mid = (len + 1) / 2;

        // base case 
        if (len == 1)
            return to_string(stoi(n) - 1);

        // push two special case 
        candidates.push_back(pow(10, len) + 1);
        candidates.push_back(pow(10, len - 1) - 1);

        long long prefix = stoll(n.substr(0, mid)); 

        //get the prefix of the num
        vector<long long> temp = { prefix, prefix + 1, prefix - 1 };

        // create the candidates from the frefix
        for (long long i : temp) {
            string res = to_string(i);
            if (len & 1)
                res.pop_back();
            reverse(res.begin(), res.end());
            string peep = to_string(i) + res;
            candidates.push_back(stoll(peep));
        }

        long long minDiff = LONG_LONG_MAX , result, tip = stoll(n);
        
        // chosse the min diff candidate
        for (int i = 0; i < 5; i++) {
            if (candidates[i] != tip
                && minDiff > abs(candidates[i] - tip)) {
                result = candidates[i];
                minDiff = abs(candidates[i] - tip);
            }
            else if (abs(candidates[i] - tip) == minDiff)
                result = min(result, candidates[i]);
        }

        return to_string(result);
    }

};

int main(){
    Solution solution;

    solution.nearestPalindromic("9999999999999999999");
    solution.nearestPalindromic("1122");

    return 0;
}