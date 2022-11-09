class Solution {
    //[stl::nth_element]
    //(time, space) = O(N) O(1)
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto kth = nums.begin() + (nums.size() - k);
        nth_element(nums.begin(), kth, nums.end());
        return *kth;
    }
};
