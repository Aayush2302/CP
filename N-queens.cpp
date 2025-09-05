#include<bits/stdc++.h>

using namespace std;

    bool saftey(int row, int col, const vector<string>& board, int n) {

        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }


    void helper(vector<vector<string>>&res,vector<string>board,int row,int n){

        if(row == n){
            res.push_back(board);
            return;
        }
        for(int col = 0;col<n;col++){
            if(saftey(row,col,board,n)){
                board[row][col] = 'Q';
                helper(res,board,row+1,n);
                board[row][col] = '.';
            }
            else{
                continue;
            }
        }

    }

int main(){
    vector<vector<string>>ans;
    int n=4;
    vector<string> board(n, string(n, '.'));
    
    helper(ans,board,0,n);

    for (auto& solution : ans) {
        for (auto& row : solution) {
            cout << row << endl;
        }
        cout << "------" << endl;
    }
}