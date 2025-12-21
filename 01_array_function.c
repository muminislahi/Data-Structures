#include <stdio.h> 

void create_array(int array[],int size)
{

    printf("Input the elements of the array");
    for (int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
        
    }
}


void display_array(int array[],int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%d\t",array[i]);
    }
}

int main()
{
    
    int target_no;
    printf("Input the number of elements:  \n");
    scanf("%d",&target_no);
    
    int array[target_no];

    create_array(array,target_no);
    display_array(array,target_no);
}
