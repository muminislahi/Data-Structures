#include <stdio.h>

int main() {

    int array[10];

    
    int size;
    printf("Input the number of elements in the array\n");
    scanf("%d",&size);
    

    printf("Enter the elements of the array\n");

    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("New array is ");

    for(int i=0;i<(size-1);i++)
    {
        printf("%d\t",array[i]);
    }

    return 0;
}
