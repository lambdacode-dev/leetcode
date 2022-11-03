class Solution {
    public:
    //[post order dfs]: on each post processing, calculate lenghts of both consecutive decreasing/increasing paths from the root
    //(time, space) = O(N) O(N)
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        function<array<int, 2>(TreeNode*)> dfs;//return length of  [0/1][dec/inc]-reasing path from root
        dfs = [&dfs, &longest] (TreeNode* node) {
            array<int,2> len = {1, 1};
            for(int i = 0; i < 2; ++i) {
                if(auto child =  i ? node->right : node->left) {
                    array<int, 2> childlen = dfs(child);
                    if(child->val == node->val + 1)
                        len[1] = max(len[1], 1 + childlen[1]);
                    else if(child->val == node->val - 1)
                        len[0] = max(len[0], 1 + childlen[0]);
                }
            }
            longest = max(longest, len[0] + len[1] - 1);
            return len;
        };
        dfs(root);
        return longest;
    }
};
