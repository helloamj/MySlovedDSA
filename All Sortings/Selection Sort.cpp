#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int *arr,int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        if(min_idx!=i)
            swap(arr[min_idx], arr[i]);
    }
}
int main() {
    int arr[5]={5,4,3,2,1};
    SelectionSort(arr,5);
    for(int i=0;i<5;i++)
    cout<<arr[i];
    return 0;
}
