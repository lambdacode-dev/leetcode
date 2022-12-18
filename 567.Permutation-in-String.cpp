class Solution {
    //[sliding window to match permutation frequency ID]
    //(time, space) = O(N1+N2) O(1)
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Freq;
        for(auto c : s1) s1Freq[c]++;
        for(int to_match = s1.size(), i = 0, j = 0; j < s2.size(); ++j) {
            auto shrink_left = [&s1Freq, &i, &s2, &to_match]() {
                s1Freq[s2[i++]]++;
                to_match++;
            };
            auto itr = s1Freq.find(s2[j]);
            if(itr == s1Freq.end()) {
                while(i < j)
                    shrink_left();
                ++i;
            }
            else {
                if(!itr->second) {
                    do {
                        shrink_left();
                    } while(s2[i-1] != s2[j]);
                }
                itr->second--;
                if(!--to_match)
                    return true;
            }
        }
        return false;
    }
}
