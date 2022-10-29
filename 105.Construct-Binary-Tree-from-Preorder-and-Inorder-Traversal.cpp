class Solution {
    //[divide and conquer]: hash-find root in inorder and recurse on left and right trees
    //(time, space) = O(N), O(N)
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> val2index; // in preorder 
        for(int i = inorder.size() - 1; i >= 0; --i) {
            val2index[inorder[i]] = i;
        }
        function<TreeNode*(int pstart, int istart, int iend)> divide_and_conquer;
        divide_and_conquer = [&divide_and_conquer,&val2index, &preorder, &inorder](int pstart, int istart, int iend) {
            if(istart >= iend )
                return (TreeNode*)0;
            
            int iroot = val2index[preorder[pstart]]; // root node in inorder
            
            return new TreeNode(preorder[pstart],
                                divide_and_conquer(pstart+1, istart, iroot),
                                divide_and_conquer(pstart+1 + (iroot - istart), iroot + 1, iend)
                                );
        };
        return divide_and_conquer(0, 0, inorder.size());
    }
};
