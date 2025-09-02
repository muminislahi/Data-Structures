#include <stdio.h>

int main() {

    int array[20];
    
    int size;
    printf("Input the number of elements in the array \n");
    scanf("%d",&size);

    printf("Enter the elements of the array\n");

    for (int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }

    if(size<20)
    {
        for (int i=size-1 ;i>=0;i--)
        {
            array[i+1]=array[i];
        }

        size++;
        

        printf("\nEnter the element to be inserted at the beginning\n");
        scanf("%d",&array[0]);


        for(int i=0;i<size;i++)
        {
            printf("%d\t",array[i]);
        }
    }


    else 
        printf("Array full");


    return 0;
}
