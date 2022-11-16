//TC: O(n^2) SC: O(1)


#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j+1]<arr[j])
            swap(arr[j+1],arr[j]);
        }
    }
}
int main() {
    int arr[5]={5,4,3,2,1};
    BubbleSort(arr,5);
    for(int i=0;i<5;i++)
    cout<<arr[i];
    return 0;
}
