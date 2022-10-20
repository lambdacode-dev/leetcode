class Solution {
    //[dfs, backtrack]
    //(time, space) = O(N^2) O(N), where N is the total elements of board
public:
    bool exist(vector<vector<char>>& board, string word) {
        function<bool(int, int, int)> dfs;
        auto backtrack = [&board, &dfs](int r, int c, int index) {
            board[r][c] |= 128;
            auto found = dfs(r,c, index);
            board[r][c] &= 127;
            return found;
        };
        dfs = [&dfs,&backtrack, &board, &word, rows = board.size(), cols = board[0].size()](int r, int c, int index) {
            if(word[index] != char(board[r][c] & 127))
                return false;
            if(++index == word.size())
                return true;

            for(auto const& [r, c] : {pair(r+1, c), pair(r-1,c), pair(r,c+1), pair(r,c-1)}) {
                if(r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] > 0) {
                    if(backtrack(r,c,index))
                        return true;
                }
            }
            return false;
        };
        for(int r = 0; r < board.size(); ++r)
            for(int c = 0; c < board[0].size(); ++c) {
                if(backtrack(r,c,0))
                    return true;
            }
        return false;
    }
};
