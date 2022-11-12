class Solution {
    //[hashing]
    //(time, space) = O(N) O(N)
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen; // only keep recent k items 
        for(int i = 0; i < nums.size(); ++i) {
            if(! seen.insert(nums[i]).second )
                return true;
            if(seen.size() > k)
                seen.erase(nums[i-k]);
        }
        return false;
    }
};
