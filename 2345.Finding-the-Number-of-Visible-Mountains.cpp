class Solution {
    //[scan and update state]: On sorted (on left base x) peaks, state being dominating peak (potentially hide next peak)
    //(time, space) = O(NlogN) O(1)
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        for(auto& peak : peaks) {
            peak[0] -= peak[1];
        }
        sort(peaks.begin(), peaks.end());

        int visiblecount = 0;
        bool ivisible = true; // is peak i visible?
        for(int i = 0, j = 1; j < peaks.size(); ++j) {
            if(peaks[i] != peaks[j]) {
                auto xi = peaks[i][0], yi = peaks[i][1];
                auto xj = peaks[j][0], yj = peaks[j][1];
                if( 2*(yj - yi) > -(xj - xi) ) {
                    visiblecount += (xj != xi && ivisible); // count peak i
                    i = j; // j becomes dominating
                    ivisible = true;
                }
            }
            else
                ivisible = false;
        }
        return visiblecount + ivisible;
    }
};
