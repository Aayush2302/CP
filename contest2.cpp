#include<bits/stdc++.h>

using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size();
        int sum = 0;
//ou are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

//Each of the two resulting sections formed by the cut is non-empty.
//The sum of the elements in both sections is equal.
//Return true if such a partition exists; otherwise return false.©leetcode
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]+grid[i+1][j] == grid[i][j+1]+grid[i+1][j+1]){
                    return true;
                }
                if(grid[i][j]+grid[i][j+1] == grid[i+1][j]+grid[i+1][j+1]){
                    return true;
                }
            }
        }
        return false;
}

int main(){
    vector<vector<int>> grid = {{1,3},{2,4}};
    bool result = canPartitionGrid(grid);
    cout << (result ? "YES" : "NO") << endl;
}