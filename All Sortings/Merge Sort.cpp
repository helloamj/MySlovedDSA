// Merge Sort
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int h) {
  
  int n1 = m - l + 1;
  int n2 = h - m;
  
  int a[n1], b[n2];
  
  for (int i = 0; i < n1; i++)
    a[i] = arr[l + i];
  
  for (int i = 0; i < n2; i++)
    b[i] = arr[m + i + 1];
  
  int i = 0, j = 0, k = l;
  
  while (i < n1 && j < n2) {
    if (a[i] <= b[j]) {
      arr[k] = a[i];
      i++;
    } else {
      arr[k] = b[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    arr[k] = a[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = b[j];
    j++;
    k++;
  }
}
void mergesort(int arr[], int l, int h) {
  if (l < h) {
    int m = (l + h) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, h);
    merge(arr, l, m, h);
  }
}
int main() {
  int arr[] = {9, 6, 7, 3, 4, 5, 2, 1, 8};
  mergesort(arr, 0, 8);
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " ";
  }
}
