#include<bits/stdc++.h>
bool checkcycle(int node,unordered_map<int , list<int> > &adj,
    unordered_map<int , bool > &visited,
    unordered_map<int , bool > &dfsvisited){
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            bool cp = checkcycle(it,adj,visited,dfsvisited);
            if(cp)return true;
        }
        else if(dfsvisited[it])
        {
            return true;
        }
    }
    dfsvisited[node]=false;
    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int , list<int> > adj;
    unordered_map<int , bool > visited;
    unordered_map<int , bool > dfsvisited;
    
    for(int i=0;i<edges.size();i++)
    {
        int a = edges[i].first;
        int b = edges[i].second;
        adj[a].push_back(b);
    }
    for(int i=1;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans = checkcycle(i,adj,visited,dfsvisited);
            if(ans)return true;
        }
    }
    return false;
}
