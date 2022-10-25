class Solution {
    //[DFS, backtracking]
    //(time, space) = O(N2^N) O(N2^N)
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        function<void(vector<int>&, int)> dfs;
        dfs = [&dfs, &nums, &subsets] (vector<int>& subset, int i) {
            if(i == nums.size())
                subsets.push_back(subset);
            else {
                subset.push_back(nums[i]);
                dfs(subset, i+1); // pick [i]
                subset.pop_back();
                dfs(subset, i+1); //skip [i]
            }
        };
        vector<int> subset;
        dfs(subset, 0);
        return subsets;
    }
};
