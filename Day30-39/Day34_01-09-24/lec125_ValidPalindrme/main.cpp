#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        shorten(s);
        cout << s;
        if(s.size() <= 1){
            return true;
        }

        int size = s.size();
        for(auto i = 0; i < size / 2; i++){
            if(s[i] != s[size - i - 1]){
                return false;
            }
        }

        return true;
    }
    
    void shorten(string& s){
        int count = 0;
        
        for(char x : s){
            if(isDigitOrChar(x)){
                s[count++] = x; 
            }
        }

        s = s.substr(0, count);
    }

    bool isDigitOrChar(char& x){
        if( ('0' <= x && x <= '9') || ('a' <= x && x <= 'z')){
            return true;
        }
        else if('A' <= x && x <= 'Z'){
            x = tolower(x);
            return true;
        }

        return false;
    }
};

int main(){
    Solution solution;

    solution.isPalindrome("A man, a plan, a canal: Panama");

    cout << int('A') << " " << int('a');
    return 0;
}