class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* node, TreeNode* p) {
        //[binary search]: update potential successor while descending the left or right sub tree
        //(time, space) = O(logN) O(1)
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
