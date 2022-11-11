class Solution {
    //[iterative dfs/backtracking]: backtrack so we can reuse sum without adding as a state to stack
    //(time, space) = O(N), O(N) 
public:
    bool hasPathSum(TreeNode* root, int sum) {
        stack<TreeNode*> stack;
        stack.push(new TreeNode (0, nullptr, root));
        while(!stack.empty()) {
            root = stack.top();
            if(auto node = root->right) {
                do {
                    stack.push(node);
                    sum -= node->val;
                }
                while( (node = node->left) );
                
                if(!stack.top()->right) {// stack top is a leaf node
                    if(!sum) return true;
                }
                root->right = nullptr; // in real project, we probably won't do this. Just a demo to achieve perf of both time and memory
            }
            else {
                sum += root->val;
                stack.pop();
            }
        }
        return false;
    }
};
