class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* node, TreeNode* p) {
        //maintain and update potential successor while descending the left or right sub tree
        TreeNode* successor = nullptr;
        while(node) {
            if(node->val > p->val) {
                successor = node;
                node = node->left;
            }
            else
                node = node->right;
        }
        return successor;
    }
};
