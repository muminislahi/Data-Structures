#include <stdio.h>
#define size_arr 20

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
//previous programs above

void insert_end(int array[],int* size)
{
    if(*size<size_arr)
    {
        int end;
        printf("enter the element to be inserted at the end");
        scanf("%d",&end);
        array[*size]=end;
        (*size)= ++(*size);
        
    }
}

int main() {

    int array[size_arr];
    
    int size;
    printf("Input the number of elements to input \n");
    scanf("%d",&size);
    create_array(array,size);
    display_array(array,size);

    insert_end(array,&size);

    
    display_array(array,size);//from previous header file 

    


    return 0;
}
