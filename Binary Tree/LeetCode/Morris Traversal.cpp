class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        //Morris Traversal
        vector<int> v;
        if(!root)return v;
        TreeNode* current =root,*pre;
        while(current)
        {
            if(!current->left)
            {
                v.push_back(current->val);
                current=current->right;
            }
            else
            {
                pre=current->left;
                while(pre->right&&pre->right!=current)
                    pre=pre->right;
                if(!pre->right)
                {
                pre->right = current;
                current = current->left;
                }
                else
                {
                    pre->right=NULL;
                    v.push_back(current->val);
                    current = current->right;

                }
            }
        }
        return v;
    }
};
