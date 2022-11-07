class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> a;
        if(!root)return ans;
        map<int , map<int , vector<int> > > mp;
        queue <pair<TreeNode* , pair<int,int> > >q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int> > temp=q.front();
           q.pop();
           int hd=temp.second.first;
           int lvl=temp.second.second;
           TreeNode* ptr=temp.first;
            mp[hd][lvl].push_back(ptr->val);
            if(mp[hd][lvl].size()>1)
                sort(mp[hd][lvl].begin(),mp[hd][lvl].end());
            if(ptr->left)
                q.push(make_pair(ptr->left,make_pair(hd-1,lvl+1)));
            if(ptr->right)
                q.push(make_pair(ptr->right,make_pair(hd+1,lvl+1)));
        }
        for(auto i:mp)
        {
            for(auto j:i.second)
            {
                for(auto k:j.second)
                    a.push_back(k);
            }
            ans.push_back(a);
            a.clear();
        }
        return ans;
        
    }
};
