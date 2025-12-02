#include <stdio.h>

int main() {
    int arr[6] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    for(int i = 1; i < n; i++) {
        int key = arr[i];     
        int j = i - 1;

        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;     
    }

   
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
