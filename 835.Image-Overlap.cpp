class Solution {
public:
    int largestOverlap(vector<vector<int>>& _img1, vector<vector<int>>& _img2) {
        int rows = _img1.size();
        int cols = _img1.front().size();
        
        //store image rows into bitsets and use its count method
        vector<bitset<32>> img1(rows), img2(rows);
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                img1[r][c] = _img1[r][c];
                img2[r][c] = _img2[r][c];
            }
        }
        
        int overlap = 0;
        
        for(int dr = -(rows-1); dr < rows; ++dr) {
            for(int dc = -(cols-1); dc < cols; ++dc) {
                int curoverlap = 0;
                for(int r1 = 0; r1 < rows; ++r1) {
                    int r2 = r1 + dr;
                    if(r2 < 0) continue;
                    if(r2 >= rows) break;
                    auto r1r2 = (dc < 0 ? img1[r1] << -dc : img1[r1] >> dc) & img2[r2];
                    curoverlap += r1r2.count();
                }
                if(curoverlap > overlap)
                    overlap = curoverlap;
            }
        }
        
        return overlap;
    }
};
