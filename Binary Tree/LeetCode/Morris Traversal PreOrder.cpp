class Solution {
   
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
         if(!root)return v;
        TreeNode*curr=root,*pre;
        while(curr){
            if(!curr->left)
            {
                v.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                pre=curr->left;
                while(pre->right&&pre->right!=curr)
                pre=pre->right;
                if(!pre->right)
                {
                    pre->right=curr;
                    v.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    pre->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return v;
    }
};
