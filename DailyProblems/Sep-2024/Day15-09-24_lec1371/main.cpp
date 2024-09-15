#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // in this solution we can use map stored the bitmask in stead of map 
    int findTheLongestSubstring(string s) {
        // Vowels with their respective bitmask values
        unordered_map<char, int> vowels = {{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        
        unordered_map<int, int> firstOccurrence;
        firstOccurrence[0] = -1;
        
        int mask = 0;
        int maxLength = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            //character is a vowel, update the bitmask
            if (vowels.count(c)) {
                mask ^= vowels[c];
            }
            
            //bitmask has been seen before, calculate the length
            if (firstOccurrence.count(mask)) {
                maxLength = max(maxLength, i - firstOccurrence[mask]);
            } else {
                //first time we've seen this bitmask, store the index
                firstOccurrence[mask] = i;
            }
        }
        
        return maxLength;
    }
};

static const int optimize = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int main(){
    Solution solution;

    cout << solution.findTheLongestSubstring("eleetminicoworoep");

    return 0;
}