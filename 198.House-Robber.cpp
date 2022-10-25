class Solution {
    //[dynamic programming]
    // f(i,robbed) = val, total money from robbing [0, i] and with i-th house 'robbed'
    // f(i+1,true) = f(i,false) + nums[i]
    // f(i+1,false) = max(f(i,false), f(i,true))
    // (time, space) = O(N) O(1)
public:
    int rob(vector<int>& nums) {
        array<int,2> dp = {}; //dp[j](i) == f(i, j==1) 
        for(auto n : nums) {
            auto tmp = dp[1];
            dp[1] = dp[0] + n;
            if(tmp > dp[0])
                dp[0] = tmp;
        }
        return max(dp[0], dp[1]);
    }
};
