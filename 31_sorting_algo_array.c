#include <stdio.h>
#include <stdlib.h>

#define MAX 100


// Utility function for swapping
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort
void selection_sort(int arr[], int n)
{
    int i, j, min_index;
    
    for(i = 0; i < n - 1; i++)
    {
        min_index = i;
        
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        
        swap(&arr[i], &arr[min_index]);
    }
}

// Insertion Sort
void insertion_sort(int arr[], int n)
{
    int i, j, key;
    
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

// Quick Sort (Recursive)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for(j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

// Merge Sort (Recursive)
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    int i, j, k;

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Shell Sort
void shell_sort(int arr[], int n)
{
    int gap = n / 2;
    int i, j, temp;

    while(gap > 0)
    {
        for(i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i;

            while(j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }

        gap /= 2;
    }
}

// Radix Sort (for non-negative integers)
int get_max(int arr[], int n)
{
    int max = arr[0];
    int i;

    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void counting_sort(int arr[], int n, int exp) // exp = exponent
{
    int output[n];
    int count[10] = {0};
    int i;

    for(i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for(i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for(i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n)
{
    int max = get_max(arr, n);
    int exp; // exp = exponent

    for(exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(arr, n, exp);
    }
}

// Bucket Sort (for 0–100 range integers)
void bucket_sort(int arr[], int n)
{
    int i, j;

    int bucket[101] = {0};  // values from 0-100

    for(i = 0; i < n; i++)
        bucket[arr[i]]++;

    int index = 0;

    for(i = 0; i <= 100; i++)
    {
        for(j = 0; j < bucket[i]; j++)
        {
            arr[index] = i;
            index++;
        }
    }
}

// Heap Sort
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if(left_child < n && arr[left_child] > arr[largest])
        largest = left_child;

    if(right_child < n && arr[right_child] > arr[largest])
        largest = right_child;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    int i;

    for(i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for(i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Print Array
void print_array(int arr[], int n)
{
    int i;

    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[MAX];
    int n;
    int choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nSorting Options:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Shell Sort\n");
    printf("6. Radix Sort\n");
    printf("7. Bucket Sort\n");
    printf("8. Heap Sort\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: selection_sort(arr, n); break;
        case 2: insertion_sort(arr, n); break;
        case 3: quick_sort(arr, 0, n - 1); break;
        case 4: merge_sort(arr, 0, n - 1); break;
        case 5: shell_sort(arr, n); break;
        case 6: radix_sort(arr, n); break;
        case 7: bucket_sort(arr, n); break;
        case 8: heap_sort(arr, n); break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nSorted ");
    print_array(arr, n);

    return 0;
}
