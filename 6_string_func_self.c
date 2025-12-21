#include <stdio.h>
#define size_arr 20

int str_len(char* array)
{
    int length=0;
    for(int i=0;i<size_arr;i++)
    {
        if(array[i]=='\0')
            break;

        else 
            length++;

    }

    return length-1;
}


void str_copy(char* array,char* array_2)
{
    for(int i=0;i<size_arr;i++)
    {
        if(array_2[i]!='\0')
        {
            array[i]=array_2[i];
        }
        
        else 
        {
            array[i]='\0';
        }
    }
}

void str_concat(char* array,char* array_2)
{
    char array_3[2*size_arr];

    int length1=str_len(array);
    int length2=str_len(array_2);
    int i,j=0;

    for(i=0;i<length1;i++)
    {
        array_3[i]=array[i];
    }

    for(i=length1;i<(length1+length2)&&j<length2;i++)
    {
        array_3[i]=array_2[j];
        j++;
        
    }
    array_3[length1+length2]='\0';
    printf("The new string is %s\n",array_3);
}


void str_reverse(char* array)
{
    char temp;
    int length=str_len(array);
    int j=length-1;

    for(int i=0;i<length/2;i++)
    {
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
        j--;
    }
    printf("The final string is %s",array);
}


int str_compare(char* array,char *array2)
{

    int length1= str_len(array);
    int length2=str_len(array2);
    if (length1==length2)
    {
        for(int i=0;i<length1;i++)
        {
            if(array[i]!=array2[i])
            {
                return array[i]-array2[i];
            }            
        }
        return 0;
    }

    else 
        printf("The strings are not same\n");

}

int main() 
{

    char array[size_arr],array_2[size_arr];
    char choice;


    do 
    {
        printf("Which function do you want to use?\n");
        printf("1) str length\n2) str copy\n3) str concatenate\n4) str reverse\n5) str compare\n");
        printf("Enter the number against your choice. Enter 0 for termination\n");

        scanf("%d",&choice);
        while (getchar()!='\n')
        {}

        switch(choice)
        {
            case 1:
                printf("Enter the string\n");
                fgets(array,sizeof(array),stdin);
                printf("The length of the string is %d\n",str_len(array));
                break;

            case 2:
                printf("Enter the first string\n");
                fgets(array,sizeof(array),stdin);

                printf("Enter the string to be copied to the previous string\n");
                fgets(array_2,sizeof(array_2),stdin);

                str_copy(array,array_2);
                printf("The new string is %s",array);

                break;

            case 3:
                printf("Enter the first string\n");
                fgets(array,sizeof(array),stdin);

                printf("Enter the string to be copied to the previous string\n");
                fgets(array_2,sizeof(array_2),stdin);

                str_concat(array,array_2);
                break;

            case 4:

                printf("Enter the string to be reversed\n");
                fgets(array,sizeof(array),stdin);

                str_reverse(array);
                break;

            case 5: 
            {    printf("Enter the first string\n");
                fgets(array,sizeof(array),stdin);

                printf("Enter the string to be compared to the previous string\n");
                fgets(array_2,sizeof(array_2),stdin);

                int compare=str_compare(array,array_2);
                //check if braces are needed here since you have declared a var inside case
                
                if(compare==0)
                    printf("The strings are same\n");

                else if(compare==-1)
                    printf("The strins are not same and sting 1 is lexographically smaller than string 2\n");

                else if(compare==1)
                    printf("The strings are not equal and string 1 is lexographically greater than string 2\n");

                break;
            }    

        }    
    }while(choice!=0);
    

    return 0;

}
