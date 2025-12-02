#include <stdio.h>

void merge(int a[], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    int temp[100];   

    
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

   
    while(i <= mid) {
        temp[k++] = a[i++];
    }

    
    while(j <= r) {
        temp[k++] = a[j++];
    }

    
    for(int x = 0; x < k; x++) {
        a[l + x] = temp[x];
    }
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);       
        mergeSort(a, mid + 1, r);  

        merge(a, l, mid, r);        
    }
}

int main() {
    int arr[6] = {6, 3, 9, 5, 2, 8};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
