class Solution {
    //[3 pointers merge right to left]
    //(time, space) = O(m+n) O(1)
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(auto i = nums1.rbegin() + n, j = nums2.rbegin(), k = nums1.rbegin(); j != nums2.rend(); )
            *k++ = (i != nums1.rend() && *i >= *j)?  *i++ : *j++;
    }
};
