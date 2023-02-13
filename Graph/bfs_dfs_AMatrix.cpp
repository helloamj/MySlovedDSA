#include<bits/stdc++.h>
using namespace std;

    int arr[10][10]={0};
void bfs(int n)
{
   int vis[10]={0};
   queue<int> q;
   q.push(n);
   vis[n]=true;
   while(!q.empty())
   {
      int x = q.front();
      q.pop();
      cout<<x<<" ";
      for(int i=0;i<10;i++)
      {
        if(arr[x][i]==1&&!vis[i])
          {
            vis[i]=1;
            q.push(i);
          }
      }
      
   }
}
int dvis[10]={0};
void dfs(int n)
{
    dvis[n]=true;
    cout<<n<<" ";
    for(int i=0;i<10;i++)
      {
        if(arr[n][i]==1&&!dvis[i])
            dfs(i);
      }
}
int main()
{
    for(int i=0;i<5;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    bfs(1);
    cout<<endl;
    dfs(1);
}
//1 2 3 4 2 5 4 5 1 5