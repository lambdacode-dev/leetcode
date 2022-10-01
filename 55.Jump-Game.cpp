class Solution {
public:
    bool canJump(vector<int>& nums) {
        //dp like: iterative from right end to left, and keep the least k for dp[k] = true
        //(time, space) = O(N) O(1)
        int least = nums.size()-1;
        for(int j = nums.size() - 2; j >= 0; --j) {
            if(j + nums[j] >= least)
                least = j;
        }
        return least == 0;
    }
};
