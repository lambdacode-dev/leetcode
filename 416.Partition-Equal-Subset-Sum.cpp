class Solution {
public:
    //[iterative DP]: f_i(sum) -> bool (is there a subset of [0,i) with given sum?)
    //base: f_0(sum) = (sum == 0)
    //iteration f_i(sum) true => f_(i+1)(sum) true and f_(i+1)(sum + nums[i]) true
    //(time, space) = O(N*S) O(S) where N is set size, and S is set total
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 0x01) return false;
        sum >>= 1;

        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(auto const& n : nums) {
            for(int s = sum-n, s2 = sum; s >= 0; --s, --s2) {
                if(dp[s]/*dp_i*/ && !dp[s2]/*dp_i+1*/)
                    dp[s2] = true;
            }
            if(dp.back())
                return true;
        }
        return false;
    }
};
