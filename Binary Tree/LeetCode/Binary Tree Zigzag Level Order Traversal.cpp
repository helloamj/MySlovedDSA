class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         bool flag=true;
        int  cnt=0;
        vector<vector<int>> v;
        if(root==NULL)return v;
        vector<int> v0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                if(flag==false)
                    reverse(v0.begin(),v0.end());
                
                v.push_back(v0);
                v0.clear();
                flag=!flag;
                if(!q.empty())
                {
                    q.push(NULL);
                }
               
            }
            else
            {
                v0.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            }
        }
        return v;
    }
};
