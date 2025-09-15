#include <stdio.h>

int main() {

    int array[10];
    printf("Number of elements to input\n");

    int count,k;
    scanf("%d",&count);


    
    if(count)
    {

        printf("Enter the elements of the array\n");
        for(int i=0;i<count;i++)
        {
            scanf("%d", &array[i]);
        }

        printf("Which position needs to be deleted?");
        scanf("%d",&k);

        for (int i=(k-1);i<count;i++)
        {
            array[i]=array[i+1];   
        }
        count--;

        for(int i=0;i<count;i++)
        {
            printf("%d\t",array[i]);
        }
    }

    else 
        printf("Not enough elements");
        
    return 0;
}
