class Solution {
    //[backtracking] sort and then backtrack with handling of repetitive number.
    //(time, space) = O(N2^N) O(N2^N)
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        function<void(vector<int>&, int)> dfs;
        dfs = [&dfs, &nums, &subsets] (vector<int>& subset, int i) {
            if(i == nums.size())
                subsets.push_back(subset);
            else {
                int multiplicity = 1;
                int j = i+1;
                for(; j < nums.size() && nums[j] == nums[i]; ++j, ++multiplicity);
                for(int m = 0; m <= multiplicity; ++m) { // m: how many occurrences of nums[i]
                    dfs(subset, j); 
                    subset.push_back(nums[i]);
                }
                subset.resize(subset.size() - (multiplicity+1));
            }
        };
        vector<int> subset;
        dfs(subset, 0);
        return subsets;
    }
};
