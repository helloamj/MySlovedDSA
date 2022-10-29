class Solution {
    private:
   void inortr(TreeNode*root,TreeNode*&tree,TreeNode*&tail){
        if(root==NULL)return ;
       inortr(root->left,tree,tail);
       if(tree==NULL)
       {
           tail=new TreeNode(root->val);
           tree=tail;
       }
       else
       {
           TreeNode* temp=new TreeNode(root->val);
           tail->right=temp;
           tail=temp;
           temp=NULL;
           delete temp;
       }
       inortr(root->right,tree,tail);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* tree=NULL;
        TreeNode* tail=tree;
        inortr(root,tree,tail);
        return tree;
    }
};
