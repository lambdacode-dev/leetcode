class Solution {
    //[dynamic programming]
    // f_(i)(b, f) = val : maximal val robbed from houses[0,i], while b/f: 0/i-th house robbed
    // f_(i+1)(b, f) = f_(i)(b, false) + nums[i], if i not last house or b is false
    // f_(i+1)(b, false) = max of f_(i)(b, *)
    // (time, space) = O(N) O(1)
public:
    int rob(vector<int>& nums) {
        int dp[2][2] = {}; //dp[b][f] = f_i(b,f)
        dp[1][1] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int dp1[] = { dp[0][1], dp[1][1] };
            dp[0][1] = dp[0][0] + nums[i];
            if(i != nums.size()-1)
                dp[1][1] = dp[1][0] + nums[i];
            for(int b = 0; b < 2; ++b)
                dp[b][0] = max(dp[b][0], dp1[b]);
        }
        return max(max(dp[0][0], dp[0][1]), max(dp[1][0], dp[1][1]));
    }
};
