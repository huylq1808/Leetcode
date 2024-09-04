#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<string> obstacleSet;
        
        for(auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        int x = 0, y = 0; // index
        int directionIndex = 0; // bègin direction 
        int max_distance = 0;

        for(int command : commands) {
            if(command == -2) { // turn left
                directionIndex = (directionIndex + 3) % 4;
            } 
            else if(command == -1) { // turn right
                directionIndex = (directionIndex + 1) % 4;
            } 
            else { // move
                for(int step = 0; step < command; ++step) {
                    int nextX = x + directions[directionIndex][0];
                    int nextY = y + directions[directionIndex][1];

                    if(obstacleSet.count(to_string(nextX) + "," + to_string(nextY))) {
                        break; // seen the obstacle
                    }

                    x = nextX;
                    y = nextY;
                    max_distance = max(max_distance, x * x + y * y); 
                }
            }
        }

        return max_distance;
    }
};

int main(){
    

    return 0;
}