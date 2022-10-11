class Solution {
    //[rolling hash, dfs]: build subtree hash key and unique id with post order dfs 
    //(time, space) = O(N) O(N)
    using Key = int;
    using Id = int;
    static constexpr int lweight = 401;
    static constexpr int rweight = 401*401;
    unordered_map<TreeNode*, Id> tree2id;
    unordered_map<Key, Id> key2id;
    vector<int> keys;
    unordered_map<Id, size_t> id2freq;
    vector<TreeNode*> uniquetree;
    Id buildTreeId(TreeNode* node) {
        auto key = tree2id[node->left] * lweight + tree2id[node->right] * rweight + (node->val + 201);
        auto [itr, ok] = key2id.insert( {key, keys.size() });
        Id id = itr->second;
        if(ok)
            keys.push_back(key);
        
        return id;
    }
    void dfs(TreeNode* node) {
        if(!node) return;
        dfs(node->left);
        dfs(node->right);
        auto id = buildTreeId(node);
        tree2id[node] = id;
        if(++id2freq[id] == 1)
            uniquetree.push_back(node);
    }
    public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        keys.push_back(0);
        tree2id[nullptr] = 0;
        key2id[0] = 0;
        id2freq[0] = 1;
        vector<TreeNode*> duplicate;
        dfs(root);
        for(auto const& tree : uniquetree) {
            if(id2freq[tree2id[tree]] > 1) {
                duplicate.push_back(tree);
            }
        }
        return duplicate;
    }
};
