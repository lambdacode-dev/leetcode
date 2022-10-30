class Solution {
    //critical observation: we can restrict each step to match/move only one character without loss of generality
    //[iterative DP]: f_i(j): s0[0,i) and s1[0,j) interleave to s[0, i+j)
    //base: f_0(0) = true
    //iteration:
    // f_i(j) => f_i(j+1) : matching s1[j] to s[i+j] if equal
    // f_i(j) => f_i+1(j) : matching s0[i] to s[i+j] if equal
    // (time, space) : O(MN) O(N) where M/N are size of 1st/2nd strings.
public:
    bool isInterleave(string s0, string s1, string s) {
        if(s0.size() + s1.size() != s.size())
            return false;
        
        vector<bool> dp(s1.size() + 1);
        dp[0] = true;
        
        for(int i = 0; i <= s0.size(); ++i) {
            for(int j = 0; j < s1.size(); ++j) { //update this row: check/match s1[j]  
                if(!dp[j+1] && dp[j] && s1[j] == s[i+j])
                    dp[j+1] = true;  
            }
            for(int j = 0; j <= s1.size(); ++j) { //update next row: check/match s0[i]
                dp[j] = dp[j] && s0[i] == s[i+j];
            }
        }
        return dp[s1.size()];
    }
};
