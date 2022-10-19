class Solution {
public:
    //[frequency count]: represent anagram as frequency table, and
    //                   scan left to right to update/match given anagram
    //(time, space): O(N), O(1)
    vector<int> findAnagrams(string s, string p) {
        int Freq[26] = {}; // from p
        int freq[26] = {}; // from scanning s

        int j = 0;
        for(; j < p.size() && j < s.size(); ++j) {
            Freq[p[j]-'a']++;
            freq[s[j]-'a']++;
        }
        for(int k = j; k < p.size(); ++k) {
            Freq[p[j]-'a']++;
        }

        int diffcount = 0;
        for(int i = 0; i < 26; ++i)
            diffcount += (Freq[i] != freq[i]);

        vector<int> indices;
        for(int i = 0; j <= s.size(); ++j, ++i) {
            if(!diffcount)
                indices.push_back(i);

            if(j < s.size())
            {
                if(freq[s[i]-'a']-- == Freq[s[i]-'a'])      ++diffcount;
                else if(freq[s[i]-'a'] == Freq[s[i]-'a'])   --diffcount;

                if(freq[s[j]-'a']++ == Freq[s[j]-'a'])      ++diffcount;
                else if(freq[s[j]-'a'] == Freq[s[j]-'a'])   --diffcount;
            }
        }
        return indices;
    }
};



