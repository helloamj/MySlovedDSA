#include<bits/stdc++.h>
using namespace std;
unordered_map<int , vector<int> > mp;
bool cycle=false;
bool iscycle(int i,vector<bool> &vis,vector<bool> &st)
{
    st[i]=true;
    if(!vis[i])
    {
        vis[i]=true;
        for(auto x:mp[i])
        {
            if(!vis[x] and iscycle(x,vis,st))
            return true;
            if(st[x])
            return true;
        }
    }
    
        st[i]=false;
        return false;
}
int main ()
{
    int n,m;
    cout<<"Enter no of nodes and edges"<<endl;
    cin>>n>>m;
    for(int i = 0;i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
    }
    vector<bool> vis(n,0),st(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && iscycle(i,vis,st))
        {
            cycle=true;
        }
    }
    if(cycle)cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;
}
