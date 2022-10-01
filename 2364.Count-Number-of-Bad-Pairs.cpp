class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //count good buddy groups: all have same i - nums[i] for any in the same good buddy group
        //(time,space) = O(N) O(N)
        for(int i = 0; i < nums.size(); ++i)
            nums[i] -= i;
        
        unordered_map<int, int> groups;
        for(int i = 0; i < nums.size(); ++i)
            groups[nums[i]]++;
        
        long long goodpairs = 0;
        for(auto const& [n, sz] : groups) {
            goodpairs += (long long)(sz)*(sz-1)/2;
        }
        
        return nums.size() * (nums.size()-1) / 2 - goodpairs;
    }
};
