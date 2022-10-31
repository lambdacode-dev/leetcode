class Solution {
    //[iterative dynamic programming]
    //f(i) = lenght of longest continous suffix of s[0,i)
    //base f(0) = 0
    //iteration: f(i+1) = 1 if s[i-1] + 1 != s[i], f(i) + 1 otherwise
    //(time, space) = O(N) O(1)
public:
    int longestContinuousSubstring(string s) {
        int longest = 1, curlen = 1;
        for(int i = 0, j = 1; j < s.size(); ++i, ++j) {
            if(s[j] == s[i] + 1)
                ++curlen;
            else {
                if(curlen > longest)
                    longest = curlen;
                curlen = 1;
            }
        }
        return max(longest, curlen);
    }
};
