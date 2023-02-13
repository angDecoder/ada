#include <iostream>
using namespace std;

int partition(int arr[], int m, int n){
    if(n>m){
        int pivot = arr[m];
        int i = m+1;
        int j = n;
        while(i<=j){
            while(i<=n && arr[i]<=pivot) i++;
            while(j>=m && arr[j]>pivot) j--;
            if(i<j){
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[m], arr[j]);
        return j;
    }
}

void quickSort(int arr[], int m, int n){
    if(m<n){
        int pivot = partition(arr, m, n);
        quickSort(arr, m, pivot-1);
        quickSort(arr, pivot+1, n);
    }
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}