#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        string buffer = "";
        stringstream ss_1(s1);
        while(ss_1 >> buffer){
            mp[buffer]++;
        }

        stringstream ss_2(s2);
        while(ss_2 >> buffer){
            mp[buffer]++;
        }

        vector<string> result;
        for(auto& x : mp){
            if(x.second == 1){
                result.push_back(x.first);
            }
        }

        return result;
    }
};

int main(){
    Solution solution;

    vector<string> result = solution.uncommonFromSentences("this apple is sweet", "this apple is sour");

    for(string x : result){
        cout << x << " ";
    }

    return 0;
}



