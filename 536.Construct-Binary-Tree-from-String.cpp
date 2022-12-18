class Solution {
    //[recursive parsing on istringstream]
    //(time, space) = O(N) O(N)
public:
    TreeNode* str2tree(string s) {
        istringstream is(s);
        std::function<TreeNode*()> parse;
        parse = [&parse, &is]() {
            int val;
            is >> val;
            if(!is) return (TreeNode*)(0);

            TreeNode *l = nullptr, *r = nullptr;
            if(is.peek() == '(') { char c; is >> c; l = parse(); is >> c; }
            if(is.peek() == '(') { char c; is >> c; r = parse(); is >> c; }
            return new TreeNode(val, l, r);
        };
        return parse();
    }
};
