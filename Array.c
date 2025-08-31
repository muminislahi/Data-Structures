#include <stdio.h>

void displayArray(const int arr[], int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int addAtBeginning(int arr[], int size, int element, int capacity) {
    if (size >= capacity) {
        printf("Error: Array overflow!\n");
        return size;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    return size + 1;
}

int addAtEnd(int arr[], int size, int element, int capacity) {
    if (size >= capacity) {
        printf("Error: Array overflow!\n");
        return size;
    }
    arr[size] = element;
    return size + 1;
}

int deleteFromBeginning(int arr[], int size) {
    if (size <= 0) {
        printf("Error: Array underflow!\n");
        return size;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int deleteFromEnd(int arr[], int size) {
    if (size <= 0) {
        printf("Error: Array underflow!\n");
        return size;
    }
    return size - 1;
}

int main() {
    int arr[20] = {10, 20, 30, 40, 50};
    int size = 5;
    int capacity = 20;

    displayArray(arr, size);

    size = addAtBeginning(arr, size, 5, capacity);
    displayArray(arr, size);

    size = addAtEnd(arr, size, 60, capacity);
    displayArray(arr, size);

    size = deleteFromBeginning(arr, size);
    displayArray(arr, size);

    size = deleteFromEnd(arr, size);
    displayArray(arr, size);

    return 0;
}
