class Solution {
    //[dynamic programming]: merge sort to update scores and sharing score on same values
    //(time, space) = O(N) O(1)
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long score1 = 0, score2 = 0;
        int i = 0, j = 0;
        for(; i < nums1.size() && j < nums2.size(); ) {
           if(nums1[i] < nums2[j])      score1 += nums1[i++]; 
           else if(nums1[i] > nums2[j]) score2 += nums2[j++];
           else                         score1 = score2 = max(score1, score2) + nums2[(i++, j++)];
        }
        for(; i < nums1.size(); ) score1 += nums1[i++];
        for(; j < nums2.size(); ) score2 += nums2[j++];
        return max(score1, score2) % (1'000'000'000 + 7);
    }
}
