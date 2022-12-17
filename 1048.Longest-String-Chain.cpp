class Solution {
    //[sort and incremental chain build]
    //(time, space) = O(N^2) O(N), where N is total letters in words
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto const& a, auto const& b) { return a.size() < b.size(); });
        unordered_map<string, int> chain2len[2]; // last word of chain -> chain length: for previous and current
        int maxchain = 0;
        for(int cursz = 0, i = 0, p/*revchain*/ = 0, c/*urchain*/ = 1; i < words.size(); ++i) {
            if(words[i].size() == cursz) {
                int len = 1;
                for(auto const& [prevword, prevlen] : chain2len[p]) {
                    auto predecessor = [](string const& prevword, string const& word) {
                        for(int i = 0, j = 0, diff = 0; j < word.size(); ++j) {
                            if(prevword[i] != word[j]) {
                                if(++diff > 1)
                                    return false;
                            }
                            else ++i;
                        }
                        return true;
                    };
                    if(predecessor(prevword, words[i]) && prevlen + 1 > len)
                        len = prevlen + 1;
                }
                chain2len[c][words[i]] = len;
                maxchain = max(maxchain, len);
            }
            else {
                swap(p, c); // switch previous and current chains
                if(words[i].size() > cursz + 1)
                    chain2len[p].clear();
                chain2len[c].clear();
                cursz = words[i].size();
                --i;
            }
        }
        return maxchain;
    }
}
