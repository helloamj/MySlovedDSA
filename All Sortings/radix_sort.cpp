#include<bits/stdc++.h>
using namespace std;
int getMax(int arr[],int n)
{
    int mxx=arr[0];
    for(int i=1;i<n;i++)
      mxx=max(arr[i],mxx);
      return mxx;
}
void counting(int arr[],int n, int e)
{
   int count[10]={0};
   for(int i=0;i<n;i++)
   count[((arr[i]/e)%10)]++;
   for(int i=1;i<=9;i++)
   count[i]+=count[i-1];
   int op[n];
   for( int i=n-1;i>=0;i--){
      op[count[((arr[i]/e)%10)]-1]=arr[i];
      count[((arr[i]/e)%10)]--;
      }
    for (int i = 0; i < n; i++)
    arr[i] = op[i];
}
void rs(int arr[],int n)
{
   int m= getMax(arr,n);
   for(int e=1;m/e>0;e*=10)
   counting(arr,n,e);
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
    rs(arr,n);
    display(arr,n);
    return 0;
}