class BSTIterator {
    //[inorder dfs with direct stack manipulation]
    //(time, space) = O(1) O(tree_height)
    stack<TreeNode*> stack;
    void leftdescend(TreeNode* root) {
        for(; root; root = root->left)
            stack.push(root);
    }
public:
    BSTIterator(TreeNode* root) { 
        leftdescend(root);
    }
    
    int next() {
        int val = stack.top()->val;
        auto root = stack.top()->right;
        stack.pop();
        leftdescend(root);
        return val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
};
