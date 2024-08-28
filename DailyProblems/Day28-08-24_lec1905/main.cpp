#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// class Solution {
// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         int m = grid1.size();
//         int n = grid1[0].size();

//         vector<vector<int>> unionGrid(m, vector<int>(n, 0));
//         int countIsland = 0;
//         queue<pair<int, int>> travel;

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 // Find a new island
//                 if(grid2[i][j] == 1 && grid1[i][j] == 1 && !unionGrid[i][j]){
                    
//                     bool isSubIsland = true;
//                     pair<int, int> temp = {i, j};
//                     travel.push(temp);

//                     while(!travel.empty()){
//                         temp = travel.front();
//                         travel.pop();
//                         unionGrid[temp.first][temp.second] = 1;

//                         // Checking 4 sides
//                         if(checking(grid1, grid2, {temp.first, temp.second - 1}) && !unionGrid[temp.first][temp.second - 1]){
//                             travel.push({temp.first, temp.second - 1});
//                         }

//                         if(checking(grid1, grid2, {temp.first - 1, temp.second}) && !unionGrid[temp.first - 1][temp.second]){
//                             travel.push({temp.first - 1, temp.second});
//                         }

//                         if(checking(grid1, grid2, {temp.first, temp.second + 1}) && !unionGrid[temp.first][temp.second + 1]){
//                             travel.push({temp.first , temp.second + 1});
//                         }

//                         if(checking(grid1, grid2, {temp.first + 1, temp.second}) && !unionGrid[temp.first + 1][temp.second]){
//                             travel.push({temp.first + 1, temp.second});
//                         }
//                     }

//                     // Increase the count if this is a valid sub-island
//                     countIsland++;
//                 }
//             }
//         }

//         return countIsland;
//     }

//     bool checking(vector<vector<int>>& grid1, vector<vector<int>>& grid2, pair<int,int> position){
//         int m = grid1.size();
//         int n = grid1[0].size();

//         // Check if within grid bounds
//         if(position.first >= m || position.second >= n || position.first < 0 || position.second < 0){
//             return false;
//         }

//         // Check if the position in grid2 is land and matches grid1
//         return grid2[position.first][position.second] == 1 && grid1[position.first][position.second] == 1;
//     }
// };

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int countIsland = 0;

        // Traverse each cell in grid2
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // If we find land in grid2 that has not been checked
                if(grid2[i][j] == 1) {
                    // Check if this island in grid2 is a sub-island
                    if(dfs(grid1, grid2, i, j)) {
                        countIsland++;
                    }
                }
            }
        }

        return countIsland;
    }

private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();

        // Check if out of bounds or water in grid2
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
            return true;
        }

        // If there's land in grid2 but not in grid1, this can't be a sub-island
        if(grid1[i][j] == 0 && grid2[i][j] == 1) {
            return false;
        }

        // Mark this cell in grid2 as visited by setting it to 0 (water)
        grid2[i][j] = 0;

        // Perform DFS in all four directions
        bool isSubIsland = true;
        isSubIsland &= dfs(grid1, grid2, i - 1, j);
        isSubIsland &= dfs(grid1, grid2, i + 1, j);
        isSubIsland &= dfs(grid1, grid2, i, j - 1);
        isSubIsland &= dfs(grid1, grid2, i, j + 1);

        return isSubIsland;
    }
};


int main(){
    Solution solution;

    vector<vector<int>> grid1{
        {1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}
    };

    vector<vector<int>> grid2{
        {1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}
    };

    cout << solution.countSubIslands(grid1, grid2);



    return 0;
}