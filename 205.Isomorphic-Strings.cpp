class Solution {
    //[check map is one on one]
    //(time, space) = O(N) O(1)
public:
    bool isIsomorphic(string s, string t) {
        char map[256] = {0};
        int count[256] = {0};
        for(int i = s.size() - 1; i >= 0; --i) {
            if(!map[s[i]]) {
                map[s[i]] = t[i];
                if(++count[t[i]] > 1)
                    return false;
            }
            else if(map[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
