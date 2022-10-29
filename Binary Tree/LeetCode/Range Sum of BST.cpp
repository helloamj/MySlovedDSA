class Solution {
public:
   void inortr(TreeNode* root,int low,int high,int &sum)
   {
       if(root==NULL)
           return;
       inortr(root->left,low,high,sum);
       if(root->val>=low&&root->val<=high)sum+=root->val;
       inortr(root->right,low,high,sum);
   }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        inortr(root,low,high,sum);
        return sum;
    }
};
