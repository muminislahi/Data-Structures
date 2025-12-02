#include <stdio.h>

int main() {
    int arr[5] = {5, 1, 4, 2, 8};
    int n = 5;
    int i, j, temp;

    
    for(i = 0; i < n - 1; i++) {          
        for(j = 0; j < n - 1 - i; j++) {    
            if(arr[j] > arr[j + 1]) {    
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
