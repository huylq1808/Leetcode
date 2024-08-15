#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        solve(s, 0, 0, "", result);

        return result;
    }

    void solve(string& s, int position, int amountOfDot, string IPAddress, vector<string>& result){
        if(amountOfDot == 4 && position >= s.size()){
            result.push_back(IPAddress);
        }

        for(int i = 1; i < 4 && i + position <= s.size(); i++){
            string subString = s.substr(position, i);

            if(i != 1 && (subString[0] == '0' || stoi(subString) > 255)){
                return;
            }

            if(amountOfDot == 0){
                solve(s, position + i, amountOfDot + 1, subString, result);
            }
            else{
                solve(s, position + i, amountOfDot + 1, IPAddress + '.' + subString, result);
            }
        }
    } 
};

// another solution faster 
class Solution {
public:
    vector<string> ans;
    int n;
    bool check(string s)
    {
        if(s.length()>3 || s.length()==0)
        {
            return false;
        }
        if(s[0]=='0'&& s.length()>1)
        {
            return false;
        }
        if(stoi(s) > 255)
        {
            return false;
        }
        return true;
        
    }
    string createSubstring(string s,int i,int j)
    {
        string ans;
        for(int k=i;k<j;k++)
        {
            ans+=s[k];
        }
        return ans;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12)
        {
            return {};
        }
        n=s.length();
        for(int i=1;i<n&&i<4;i++)
        {
            string first=createSubstring(s,0,i);
            if(!check(first))
            {
                continue;
            }
            for(int j=i+1;j<n&&j<i+4;j++)
            {
                string second=createSubstring(s,i,j);
                if(!check(second))
                {
                    continue;
                }
                for(int k=j+1;k<n&&k<j+4;k++)
                {
                    string third=createSubstring(s,j,k);
                    if(!check(third))
                    {
                        continue;
                    }
                    string fourth=createSubstring(s,k,n);
                    if(!check(fourth))
                    {
                        continue;
                    }
                    ans.push_back(first+"."+second+"."+third+"."+fourth);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;

    vector<string> result = solution.restoreIpAddresses("00010");
    
    for(string x : result){
        cout << x << endl;
    }

    return 0;
}