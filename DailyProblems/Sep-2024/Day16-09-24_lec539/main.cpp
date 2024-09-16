#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::vector<int> minutes;
        
        // Convert each time point to minutes
        for (const std::string& time : timePoints) {
            int hours = std::stoi(time.substr(0, 2));
            int mins = std::stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the time points
        std::sort(minutes.begin(), minutes.end());
        
        // Initialize the minimum difference to a large value
        int minDiff = 24 * 60;
        
        // Calculate the difference between consecutive time points
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = std::min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Calculate the difference between the last and the first time point
        int circularDiff = 24 * 60 - minutes.back() + minutes.front();
        minDiff = std::min(minDiff, circularDiff);
        
        return minDiff;
    }
};

int main(){

    return 0;
}