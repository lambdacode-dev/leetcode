//[backtrack on most restrictive cell]: at most 81^9 recursive calls.
//(time, space) = O(1) O(1)
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //if [index] = true : the number 'index' is already used in the row/col/box
        //[0] = count = how many trues
        using Row = array<int,10>;
        using Col = array<int,10>;
        using Box = array<int,10>;
        Row row[10] {};
        Col col[10] {};
        Box box[3][3] {};
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                if(board[r][c] != '.') {
                    row[r][board[r][c] - '0'] = true; row[r][0]++;
                    col[c][board[r][c] - '0'] = true; col[c][0]++;
                    box[r/3][c/3][board[r][c] - '0'] = true; box[r/3][c/3][0]++;
                }
            }
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
                    row[R][i] = true; row[R][0]++;
                    col[C][i] = true; col[C][0]++;
                    box[R/3][C/3][i] = true; box[R/3][C/3][0]++;

                    if(backtrack()) return true;

                    board[R][C] = '.';
                    row[R][i] = false; row[R][0]--;
                    col[C][i] = false; col[C][0]--;
                    box[R/3][C/3][i] = false; box[R/3][C/3][0]--;
                }
            }
            return false;
        };
        backtrack();
    }
};
