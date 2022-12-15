class Solution {
    //[backtrack on most restrictive cell]
    //(time, space) = O(1) O(1)
public:
    void solveSudoku(vector<vector<char>>& board) {
        //if [index] = true : the number 'index' is already used in the row/col/box
        using NumberUsed = array<bool,10>;
        NumberUsed row[10] {}, col[10] {}, box[3][3] {};
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c)
                if(board[r][c] != '.')
                    row[r][board[r][c] - '0'] = col[c][board[r][c] - '0'] = box[r/3][c/3][board[r][c] - '0'] = true;
        }
        function<int()> backtrack;
        backtrack = [&backtrack, &row, &col, &box, &board]() {
            int choices = 9;
            int R = -1, C = -1;//find the best (most restrictive) cell to plane next number
            for(int r = 0; r < 9; ++r) {
                for(int c = 0; c < 9; ++c) {
                    int mychoices = 0;
                    if(board[r][c] == '.') {
                        for(int i = 1; i <= 9; ++i) {
                            if(!row[r][i] && !col[c][i] && !box[r/3][c/3][i])
                                mychoices++;
                        }
                        if(mychoices < choices) {
                            choices = mychoices;
                            R = r;
                            C = c;
                        }
                    }
                }
            }
            if(R == -1 && C == -1)
                return true;

            for(int i = 1; i <= 9; ++i) {
                if(!row[R][i] && !col[C][i] && !box[R/3][C/3][i]) {
                    board[R][C] = '0' + i;
                    row[R][i] = col[C][i] = box[R/3][C/3][i] = true;

                    if(backtrack()) return true;

                    board[R][C] = '.';
                    row[R][i] = col[C][i] = box[R/3][C/3][i] = false;
                }
            }
            return false;
        };
        backtrack();
    }
};
