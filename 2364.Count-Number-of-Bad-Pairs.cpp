class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //[partition, hash]: count good buddy groups with same (i - nums[i])
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
