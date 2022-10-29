class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        double cnt=0,ans=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
                q.pop();
            if(temp==NULL)
            {
                if(!q.empty())
                {
                   
                    q.push(NULL);
                v.push_back(ans/cnt);
                    ans=0;
                    cnt=0;
                }
            }
            else
            {
            ans+=temp->val;
            cnt++;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            }
        }
        if(cnt)
                v.push_back(ans/cnt);
        return v;
    }
};
