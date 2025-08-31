class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

private:
    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;           
        if (c == 9) return backtrack(board, r+1, 0);
        if (board[r][c] != '.') return backtrack(board, r, c+1);

        for (char ch = '1'; ch <= '9'; ++ch) {
            if (valid(board, r, c, ch)) {
                board[r][c] = ch;
                if (backtrack(board, r, c+1)) return true;
                board[r][c] = '.';     
            }
        }
        return false;       
    }

    bool valid(const vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; ++i) {
            if (board[r][i] == ch) return false;                    
            if (board[i][c] == ch) return false;                   
            int br = 3 * (r / 3) + i / 3;                           
            int bc = 3 * (c / 3) + i % 3;                           
            if (board[br][bc] == ch) return false;              
        }
        return true;
    }
};