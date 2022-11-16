#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int *arr,int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
    key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[5]={5,4,3,2,1};
    InsertionSort(arr,5);
    for(int i=0;i<5;i++)
    cout<<arr[i];
    return 0;
}
