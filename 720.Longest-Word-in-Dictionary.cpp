class Solution {
    //[prefix tree]
    //(time, space) = O(N) O(N) where N is total string size
public:
    string longestWord(vector<string>& words) {
        struct PrefixTree { bool isword = false; PrefixTree* children[26] = {nullptr}; }
        root;
        
        // build the prefix tree
        for(auto const& word : words) {
            auto node = &root;
            for(auto c : word) {
                if( !node->children[c - 'a'] )
                    node->children[c - 'a'] = new PrefixTree();
                node = node->children[c - 'a'];
            }
            node->isword = true;
        }
        
        //dfs/back-track the tree to collect/update result
        string answer = "";
        function<void(PrefixTree*, string&)> dfs;
        dfs = [&dfs, &answer] (PrefixTree* node, string& prefix) {
            for(int i = 0; i < 26; ++i) {
                if(node->children[i] && node->children[i]->isword) {
                    prefix.push_back('a' + i);
                    if(prefix.size() > answer.size())
                        answer = prefix;
                    dfs(node->children[i], prefix);
                    prefix.pop_back();
                }
            }
        };
        
        string prefix = "";
        dfs(&root, prefix);
        return answer;
    }
};
