class Solution {
    //[rotate and 3 pointers merge in place]
    //(time, space) = O(m+n) O(1)
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        rotate(nums1.begin(), nums1.begin() + m, nums1.end());
        for(auto i = nums1.begin() + n, j = nums2.begin(), k = nums1.begin(); j != nums2.end(); )
            *k++ = (i != nums1.end() && *i <= *j)?  *i++ : *j++;
    }
};
