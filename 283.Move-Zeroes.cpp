class Solution {
public:
    //[two pointers and swap]
    //(time, space) = O(N) O(1)
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        
        //i: first 0
        int i = 0;
        while(i < sz && nums[i]) ++i; 
        
        //j: first non 0
        int j = i + 1;
        while(j < sz && !nums[j]) ++j; 
        
        while(i < j && j < sz) {
            swap(nums[i++], nums[j++]);
            while(j < sz && !nums[j]) ++j; 
        }
    }
};
