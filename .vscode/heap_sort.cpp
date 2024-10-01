#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest, temp;
    largest=i;
    int lson=i*2+1;
    int rson=i*2+2;
    if (lson<n && arr[largest]<arr[lson]){
        largest=lson;
    }
    if (rson<n && arr[largest]<arr[rson]){
        largest=rson;
    }
    if (largest==i){
        return;
    }
    if (largest!=i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n){
    int i, temp;
    for (i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for (i=n-1; i>=0; i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr, n, 0);
    }
}