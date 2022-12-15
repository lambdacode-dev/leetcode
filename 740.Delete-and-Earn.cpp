//[dynamic programm] on sorted frequency maps: freq
//f(i)[2] = sub problem on freq[0,i), with freq[i-1] skipped and chosen.
//(time, space) = O(NlogN) O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> freq;
        for(auto const& n : nums) freq[n]++;
        int f[2] = {0};
        int prev_n = -1;
        for(auto const& [n, count] : freq) {
            auto ncount = n * count;
            auto f0 = f[0], f1 = f[1];
            f[0] = max(f0, f1);
            f[1] = f0 + ncount;
            if(prev_n + 1 != n)
                f[1] = max(f[1], f1 + ncount);
            prev_n = n;
        }
        return max(f[0], f[1]);
    }
};
