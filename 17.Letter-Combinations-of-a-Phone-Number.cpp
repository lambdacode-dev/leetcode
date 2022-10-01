class Solution {
    string letters[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    string digits;
    vector<string> paths;
    void dfs(int i, string& state) {
        if(i == digits.size()) {
            if(!state.empty())
                paths.push_back(state);
        }
        else {
            for(auto c : letters[digits[i]-'0']) {
                state.push_back(c);
                dfs(i+1, state);
                state.pop_back();
            }
        }
    }
        
public:
    //[dfs, backtrack]
    //(time, space) = O(N4^N) O(N4^N)
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        string state;
        dfs(0, state); 
        return paths;
    }
};
