class Solution {
    //[frequency count]: use hash map instead of 26 elements array so unicode can be handled.
    //(time, space) = O(N) O(N) 
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> freq;
        for(auto c : s) freq[c - 'a']++;
        for(auto c : t) freq[c - 'a']--;
        return all_of(freq.begin(), freq.end(), [](auto f) { return !f.second; });
    }
};
