class Solution {
public:
    bool isSafe(vector<string> board, int r, int c, int n){
        //diagonally left
        int i=r,j=c;
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c--;
        }
        r=i;
        c=j;
        while(j>=0){
            if(board[i][j] == 'Q') return false;
            j--;
        }
        while(r<n && c>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r++;
            c--;
        }
        return true;
    }
    
    void n_queen_solve(vector<string> &board, int col, int n, vector<vector<string>> &ans){
        int i;
        if(col==n){
            ans.push_back(board);
        }

        for(i=0;i<n;i++){
            if(isSafe(board, i, col, n)){
                board[i][col] = 'Q';
                n_queen_solve(board, col+1, n, ans);
                board[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;   
        }
        n_queen_solve(board,0,n,ans);
        return ans;
    }
};