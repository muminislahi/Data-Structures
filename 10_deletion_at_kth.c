#include <stdio.h>
#define size 10

int main() {

    int array[size],target;//target is for number of elements to enter in the array

    printf("Input the number of elements to be added to the array");
    scanf("%d",&target);

    printf("Input the elements of the array");
    for(int i=0;i<target;i++)
    {
        scanf("%d",&array[i]);
    }

    if(target>1)
    {
    //delete at the beginning 
        for(int i=0;i<target;i++)
        {
            array[i]=array[i+1];
        }
        target--;


    //display the array
        for(int i=0;i<target;i++)
        {
            printf("%d\t",array[i]);
        }

    }

    else    
    {   
        printf("Not enough elements to delete");

    }    

    return 0;
}
