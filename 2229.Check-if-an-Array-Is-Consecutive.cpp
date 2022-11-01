class Solution {
    //[frequency counting]
    //(time, space) = O(N), O(N)
public:
    bool isConsecutive(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = min + nums.size() - 1;
        vector<int> count(nums.size());
        for(auto n : nums) {
            if(n > max) return false;
            if(count[n-min]++) return false;
        }
        return true;
    }
};
