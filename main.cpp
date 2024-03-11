#include <bits/stdc++.h>

using namespace std;
void BubleSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = n - 1; j > 0; j--)
            if(a[j] > a[j-1])
                swap(a[j], a[j-1]);
}
void selectionSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        int max = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] > a[max]) max = j;
        }
        if(max != i) swap(a[i], a[max]);
    }
}
void insertSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int tmp = a[i];
        int j = i - 1;
        while(j > -1 and a[j] > tmp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
        }
}
void Merge(int a[], int l, int m, int r){
    int n1 = m + 1;
    int n2 = r - m;
    int j = 0;
    int i = 0, k = 0;
    int L[n1 + 1];
    int R[n2 + 1];
    for(int i = 0; i < n1; i++)
        L[i] = a[i];
    for(int i = n1; i < r+1; i++)
        R[i - n1] = a[i];
    while(i < n1 and j < n2){
        if(L[i] < R[j]){
            a[k] = L[i];
            k++;
            i++;
        }
        else{
            a[k] = R[j];
            k++;
            j++;
        }
    }
    while(i < n1){
        a[k] = L[i];
        k++;
        i++;
    }
     while(j < n2){
        a[k] = R[j];
        k++;
        j++;
    }
}
void MergeSort(int arr[], int l, int r){
    if(l < r){
            int m = (l+r)/2;
          MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);
        Merge(arr, l, m, r);

    }

}
void quicksort(int a[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        int tmp = a[m];
        int i = l;
        int j = r;
        do{
            while(a[i] < tmp) i++;
            while(a[j] > tmp) j--;
            if(i <= j){
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }while(i <= j);
        quicksort(a, l, j);
        quicksort(a, i, r);
    }
}
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int a[7] = {1, -3, 5, -6, 8, 2, 6};
    quicksort(a, 0, 6);
    for(int i = 0; i < 7; i++)
        cout << a[i] << " ";

    return 0;
}
