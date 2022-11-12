class Solution {
    //[hashing]
    //(time, space) = O(N) O(N)
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto n : nums) {
            if( !seen.insert(n).second )
                return true;
        }
        return false;
    }
};
