class Solution {
    public:
    //[post order dfs]: on each post processing, calculate lenghts of both consecutive decreasing/increasing paths from the root
    //(time, space) = O(N) O(N)
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        function<array<int, 2>(TreeNode*)> dfs;//return length of  [0/1][dec/inc]-reasing path from root
        dfs = [&dfs, &longest] (TreeNode* node) {
            array<int,2> len = {1, 1};
            if(node->right) {
                array<int, 2> rlen = dfs(node->right);
                if(node->right->val == node->val + 1)
                    len[1] = 1 + rlen[1];
                else if(node->right->val == node->val - 1)
                    len[0] = 1 + rlen[0];
            }
            if(node->left) {
                array<int, 2> llen = dfs(node->left);
                if(node->left->val == node->val + 1)
                    len[1] = max(len[1], 1 + llen[1]);
                else if(node->left->val == node->val - 1)
                    len[0] = max(len[0], 1 + llen[0]);
            }
            longest = max(longest, len[0] + len[1] - 1);
            return len;
        };
        dfs(root);
        return longest;
    }
};
