#include<bits/stdc++.h>
using namespace std;
unordered_map<int , vector<int> > mp;
bool cycle=false;
bool iscycle(int i,vector<bool> &vis,int parent)
{
    vis[i]=true;
    for(auto x: mp[i])
    {
        if (!vis[x]) {
            if (iscycle(x,vis,i)) {
                return true;
            }
        } else if (parent!=x) {
            return true;
        }

    }
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
        mp[b].push_back(a);
    }
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && iscycle(i,vis,-1))
        {
            cycle=true;
        }
    }
    if(cycle)cout<<"Present"<<endl;
    else cout<<"Not Present"<<endl;
}
