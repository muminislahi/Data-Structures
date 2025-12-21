//program searches for all the instances of a given target and gives position (not indecies) of its occurances
#include <stdio.h>
#define size_arr 15

int main() {

    int array[size_arr],size;

    printf("How many elements do you want to input (max=%d)\n",size_arr);
    scanf("%d",&size);

//add elements to the array
    printf("Enter the elements of the array\n");

    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }

//taking the elements to be found from the user
    int target;
    printf("Which element do you want to find\n");
    scanf("%d",&target);

    int index_arr[size_arr],j=0,count=0;

//finding all the elements in the array and directly storing the position in another array
    for (int i=0;i<size;i++)
    {
        if(array[i]==target)
        {
            index_arr[j]=i+1;
            j++;
            count++;

        }
    }


    printf("%d was found at position/s\t",target);
    for(int j=0;j<count;j++)
    {
        printf("%d\t",index_arr[j]);
    }


    return 0;
}
