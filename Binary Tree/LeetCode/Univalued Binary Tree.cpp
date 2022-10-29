class Solution {
    private:
    void inordertr(TreeNode* root,int ans,bool &res)
     {
         if(root==NULL)return;
         inordertr(root->left,ans,res);
         if(ans!=root->val)res=false;
         inordertr(root->right,ans,res);
     }
public:
    bool isUnivalTree(TreeNode* root) {
        bool res=true;
        int ans =root->val;
        inordertr(root,ans,res);
        return res;
    }
};
