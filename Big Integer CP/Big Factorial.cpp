#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 void mult(int i,vector<int> &v)
 {
 	int carry=0;
 	for(int j=0;j<v.size();j++)
 	{
 		int ans=v[j]*i+carry;
 		v[j]=ans%10;
 		carry=ans/10;
 	}
 	while(carry)
 	{
 		v.push_back(carry%10);
 		carry/=10;
 	}
 }

 
int32_t main()
{
	int n;
	cin>>n;
	//cout<<n;
	vector<int> v;
	v.push_back(1);
	for(int i=2;i<=n;i++)
       mult(i,v);
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
	return 0;
}
