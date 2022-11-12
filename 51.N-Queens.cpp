class Solution {
    //[backtracking]
    //(time, space) = O(N!) O(N)
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sols;
        vector<int> pos; // queen's position in each row
        auto add2sols = [&sols, &pos, n] () {
            sols.push_back(vector<string>(n));
            auto& sol = sols.back();
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < pos[i]; ++j)   sol[i].push_back('.');
                sol[i].push_back('Q');
                for(int j = pos[i]+1; j < n; ++j) sol[i].push_back('.');
            }
        };
        auto attack = [&pos] (int C) {
            int R = pos.size();
            for(int r = 0; r < pos.size(); ++r) {
                auto c = pos[r];
                if(c == C || abs(c-C) == abs(r - R))
                    return true;
            }
            return false;
        };
        function<void(int)> backtrack;
        backtrack = [&attack, &backtrack, &add2sols, &pos, n](int r) {
            if(r == n) 
                add2sols();
            for(int c = 0; c < n; ++c) {
                if(!attack(c)) {
                    pos.push_back(c);
                    backtrack(r+1);
                    pos.pop_back();
                }
            }
        };
        backtrack(0);
        return sols;
    }
};
