#include <bits/stdc++.h>
using namespace std;
void addingraph(int a,int b ,unordered_map<int,set<int>> &mp)
{
   mp[a].insert(b);
   mp[b].insert(a);
  return;
}
void printgraph(unordered_map<int,set<int>> &mp)
{
  for(auto i:mp)
    {
      cout<<i.first<<" -> ";
      for(auto j:i.second)
        cout<<j<<" ";
      cout<<endl;
    }
}
int main() {
  unordered_map<int,set<int>> mp;
     cout<<"Enter the number of edges of graph"<<endl;
    int n;
  cin>>n;
  cout<<"Enter edges of graph"<<endl;
  for(int i=0;i<n;i++)
    {
        int a,b;
      cin>>a>>b;
      addingraph(a,b,mp);
    }
  printgraph(mp);
  return 0;
  }

// I/P: 5 1 2 2 3 3 1 3 4 1 4
