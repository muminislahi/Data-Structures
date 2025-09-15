#include <stdio.h>
#define size 15

int main() {

    int array[size],actual_no;
    printf("How many elements do you want to add?");
    scanf("%d",&actual_no);

    printf("Input the elements of the array");
    for(int i=0;i<actual_no;i++)
    {
        scanf("%d",&array[i]);
    }

    if(actual_no>1)
    {
    //delete 
        for(int i=0;i<actual_no;i++)
        {
            array[i]=array[i+1];
        }
        actual_no--;



        for(int i=0;i<actual_no;i++)
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
