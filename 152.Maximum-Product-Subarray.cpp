class Solution {
    //[dynmaic programm] p(i) = max pos product from suffix of [0, i], n(i) for min negative prod.
    //(time, space) = O(N) O(1)
    public:
    int maxProduct(vector<int>& nums) {
        int dp[2] = {0, 0}; // dp[0]: p(i), dp[1]: n(i)
        int max = INT_MIN;
        for(auto n : nums) {
            dp[0] = std::max(dp[0], 1) * n;
            dp[1] *= n;
            if(n < 0) 
                swap(dp[0], dp[1]);
            
            if(dp[0] && dp[0] > max )
                max = dp[0];
            else if(dp[1] > max)
                max = dp[1];
        }
        return max;
    }
};
