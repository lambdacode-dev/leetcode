class Solution {
    //[scan and choose]: always choose 0, and 1 can be skipped (if > k) without impacting the final solution
    //(time, space) = O(N) O(N)
public:
    int longestSubsequence(string s, int k) {
        int len = 0, i = 0;
        for(; i <= int(s.size()) - 32; ++i)
            if(s[i] == '0') ++len;
        
        s = s.substr(i);
        int n = stoi(s, nullptr, 2);
        
        for(int i = s.size() - 1, set = 0b01 << i; i >= 0; --i, set = set >> 1) {
            if(n <= k)
                return len + i + 1;
            
            if(n & set)
                n &= ~set;
            else
                ++len;
        }
        return len;
    }
};
