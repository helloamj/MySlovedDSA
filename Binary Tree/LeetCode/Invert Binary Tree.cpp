class Solution {
    private:
    TreeNode* invtree(TreeNode* root,TreeNode* res) {
        if(!root)return NULL;
        res = new TreeNode(root->val);
        res->right=invtree(root->left,res->right);
        res->left=invtree(root->right,res->left);
        return res;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* res ;
        res= invtree(root,res);
        return res;
    }
};
