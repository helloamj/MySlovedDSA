#include <bits/stdc++.h>
using namespace std;
void addingraph(int a, int b, unordered_map<int, vector<int>> &mp) {
  mp[a].push_back(b);
  mp[b].push_back(a);
  return;
}
void printgraph(unordered_map<int, vector<int>> &mp) {
  for (auto i : mp) {
    cout << i.first << " -> ";
    for (auto j : i.second)
      cout << j << " ";
    cout << endl;
  }
}
void printgraphinBFS(unordered_map<int, vector<int>> &mp) {
  unordered_map<int, bool> chk;
  queue<int> q;
  cout << endl << "BFS Traversal of the gival graph: " << endl;
  cout << "Enter the number from where to start BFS" << endl;
  int d;
  cin >> d;
  chk[d] = true;
  q.push(d);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    cout << a << " ";
    for (auto i : mp[a]) {
      if (!chk[i]) {
        chk[i] = true;
        q.push(i);
      }
    }
  }
}
void dfs(int i, unordered_map<int, bool> &chk,
         unordered_map<int, vector<int>> &mp) {
  cout << i << " ";
  chk[i] = true;
  for (auto j : mp[i]) {
    if (!chk[j]) {
      dfs(j, chk, mp);
    }
  }
}
void printgraphinDFS(int V, unordered_map<int, vector<int>> &mp) {
  unordered_map<int, bool> chk;
  cout << endl << "DFS Traversal of the gival graph: " << endl;
  for (int i = 1; i < V; i++) {
    if (!chk[i]) {
      dfs(i, chk, mp);
    }
  }
}
int main() {
  unordered_map<int, vector<int>> mp;
  cout << "Enter the number of edges of graph" << endl;
  int n;
  cin >> n;
  cout << "Enter edges of graph" << endl;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    addingraph(a, b, mp);
  }
  printgraph(mp);
  printgraphinBFS(mp);
  printgraphinDFS(5, mp);
  return 0;
}


// I/P : 5 1 2 2 3 3 1 3 4 1 4
// I/P2 : 5 1 2 1 3 1 4 2 4 1 5
