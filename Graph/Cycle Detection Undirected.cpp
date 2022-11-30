#include<bits/stdc++.h>
bool checkcycle(int n,unordered_map<int,vector<int>> &mp,
    unordered_map<int,bool> &visited,
    unordered_map<int,int> &parent){
    visited[n]=true;
    parent[n]=-1;
    queue<int>q;
    q.push(n);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto it:mp[front])
        {
            if(visited[it]==true&&parent[front]!=it)
                return true;
            else if(!visited[it]){
                q.push(it);
                parent[it]=front;
                visited[it]=true;
            }
        }
    }
    return false;
}
bool checkcycleDFS(int n,int parent,unordered_map<int,vector<int>> &mp,
    unordered_map<int,bool> &visited){
    visited[n]=true;
    for(auto it:mp[n])
    {
        if(!visited[it]){
            bool cp=checkcycleDFS(it,n,mp,visited);
        if(cp)return true;
        }
        else if (it != parent)
            return true;
    }
    return false;
    
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,vector<int>> mp;
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    for(int i=0;i<m;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
           // bool ans=checkcycle(i,mp,visited,parent);
            bool ans=checkcycleDFS(i,-1,mp,visited);
            if(ans)return "Yes";
        }
    }
    return "No";
}
