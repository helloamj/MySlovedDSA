#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map <int , vector <int> > mp;
    unordered_map <int , int> dist;
    int n;
    cout<<"Enter the number of Edges"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(auto x:mp)
    {
        dist[x.first]=INT_MAX;
    }
    dist[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        cout<<t<<" "<<dist[t]<<endl;
        for(auto x: mp[t])
        if(dist[x]==INT_MAX){
        q.push(x);
        dist[x]=dist[t]+1;
        }
    }
 
    return 0;
}
