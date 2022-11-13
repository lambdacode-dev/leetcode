class Solution {
    //[backtracking]
    //(time, space) = O(NN!) O(1) without counting result for space consumption
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        function<void(int)> backtrack;
        backtrack = [&backtrack, &ans, &nums] (int i) {
            if(i == nums.size())
                ans.push_back(nums);
            else {
                for(int j = nums.size()-1; j >= i; --j) {
                    if(i != j) swap(nums[i], nums[j]);
                    backtrack(i+1);
                    if(i != j) swap(nums[i], nums[j]);
                }
            }
        };
        backtrack(0);
        return ans;
    }
};
