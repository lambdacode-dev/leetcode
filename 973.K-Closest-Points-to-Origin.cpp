class Solution {
    //[STL nth_element]
    //(time,space) = O(N) O(1)
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto kth = points.begin() +k;
        nth_element(points.begin(), kth, points.end(), [](auto const& p1, auto const& p2) {
            return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1];
        });
        return {points.begin(), kth};
    }
};
