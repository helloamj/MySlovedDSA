class Solution {
public:
    void inortr(TreeNode * root,bool &res)
    {
        if(root==NULL)return;
        inortr(root->left,res);
        inortr(root->right,res);
        if(root->val==2)
            {
                root->val=(root->right->val||root->left->val);
                    res=root->val;
            }
            if(root->val==3)
            {
                root->val=root->right->val&&root->left->val;
                res=root->val;
            }
        
    }
    bool evaluateTree(TreeNode* root) {
          bool res=root->val;
        inortr(root,res);
        return res;
    }
};
