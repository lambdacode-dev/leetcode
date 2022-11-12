class Solution {
public:
    //[two pointers]
    //(time, space) = O(N) O(1)
    bool isSubsequence(string s, string t) {
        for(int i = 0, j = 0; i < s.size(); ++i, ++j) {
            while(j < t.size() && t[j] != s[i])
                ++j;
            if(j == t.size()) return false;
        }
        return true;
    }
};
