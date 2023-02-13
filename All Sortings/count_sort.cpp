#include<bits/stdc++.h>
using namespace std;
int getMax(int arr[],int n)
{
    int mxx=arr[0];
    for(int i=1;i<n;i++)
      mxx=max(arr[i],mxx);
      return mxx;
}
void cs(int arr[],int n)
{
   int m= getMax(arr,n);
   int count[m+1]={0};
   for(int i=0;i<n;i++)
   count[arr[i]]++;
   for(int i=1;i<=m;i++)
   count[i]+=count[i-1];
   int op[n];
   for( int i=n-1;i>=0;i--){
      op[count[arr[i]]-1]=arr[i];
      count[arr[i]]--;
      }
    for (int i = 0; i < n; i++)
    arr[i] = op[i];
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={9,8,100,197,203,456,0};
    int n= sizeof(arr)/sizeof(int);
    cout<<"Before Sorting"<<endl;
    display(arr,n);
    cout<<endl<<"After Sorting"<<endl;
    cs(arr,n);
    display(arr,n);
    return 0;
}