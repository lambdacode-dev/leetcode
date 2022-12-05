//[scan and handle transition event]: a transition happens or state changes when ever seen a letter from last.
//(time, space) = O(N) O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        s.push_back(s.back() == '0' ? '1' : '0');
        for(int i = 0, j = 0, k = 1; k < s.size(); ++k) {
            if(s[k] != s[k-1]) {
                count += min(j-i, k-j);
                i = j;
                j = k;
            }
        }
        return count;
    }
};
