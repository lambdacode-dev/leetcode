class Solution {
    //[post order binary tree traversal] to find consecutive ROOT seq path
    //(time, space) = O(N) O(N)
public:
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        function<int(TreeNode*)> dfs;
        auto update_from_child = [&dfs] (TreeNode* child, int rootval, int& len) {
            int childsol = dfs(child);
            if(rootval + 1 == child->val)
                len = max(len, childsol + 1);
        };
        dfs = [&dfs,&update_from_child, &longest](TreeNode* root) {
            int len = 1;
            if(root->left)  update_from_child(root->left, root->val, len);
            if(root->right) update_from_child(root->right, root->val, len);
            if(len > longest)
                longest = len;
            return len;
        };
        dfs(root);
        return longest;
    }
};
