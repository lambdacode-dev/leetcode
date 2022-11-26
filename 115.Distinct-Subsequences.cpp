class Solution {
    //[dynamic programming]: f_i(j) = sub problem on s[0,i) t[0,j). 
    //base f_0(*) = 0, except f_0(0) = 1: sub problem on two empty strings
    //iteration: f_i(j) -> f_(i+1)(j+1) if s[i] == t[j]
    //iteration: f_i(j) -> f_(i+1)(j)  
public:
    int numDistinct(string s, string t) {
        vector<unsigned long> dp(t.size() + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = t.size() - 1; j >= 0; --j) {
                if(s[i] == t[j])
                    dp[j+1] += dp[j];
            }
        }
        return dp.back();
    }
};
