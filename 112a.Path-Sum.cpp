class Solution {
    //[dfs]
    //(time, space) = O(N), O(N)
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        targetSum -= root->val;
        if(!root->left && !root->right)
            return !targetSum;
        
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
