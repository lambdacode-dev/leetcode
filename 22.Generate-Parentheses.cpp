//[backtrack]
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        function<void(int, int)> backtrack;
        backtrack = [&backtrack, &ans, &cur](int open/*current outstanding left (*/, int close/*total pairs to do*/) {
            if(!close)
                ans.push_back(cur);
            else {
                if(open < close) {
                    cur.push_back('(');
                    backtrack(open + 1, close);
                    cur.pop_back();
                }
                if(open) {
                    cur.push_back(')');
                    backtrack(open - 1, close - 1);
                    cur.pop_back();
                }
            }
        };
        backtrack(0, n);
        return ans;
    }
}
