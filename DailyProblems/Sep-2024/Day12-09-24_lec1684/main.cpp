#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool chr[27]{0};

        for(char x : allowed){
            chr[x - 'a'] = 1;
        }

        int count = 0;
        for(string word : words){
            for(char x : word){
                if(!chr[x - 'a']){
                    count--;
                    break;
                }
            }
            count++;
        }

        return count;
    }
};

int main(){

    return 0;
}