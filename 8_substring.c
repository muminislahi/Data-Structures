#include <stdio.h>
#define size 20

int str_len(char* array)
{
    int length=0;
    for(int i=0;i<size;i++)
    {
        if(array[i]=='\0')
            break;

        else 
            length++;

    }

    return length-1;
}




void substring_func(char* array, char *substring)
{
    int length1=str_len(array);
    int length2=str_len(substring);
    int count=0,found,k;

    if(length1>=length2)
    {
        for(int i=0;i<length1;i++)
        {
            //resetting count so that it starts afresh after a failed attempt
            count=0;
            if(array[i]==substring[0])
            {
                //k is the counter for substring array
                k=0;
               for(int j=i;j<(i+length2);j++)
               {    
                    if(array[j]==substring[k])
                    {
                        found=i+1;
                        count++;
                        //to get the first instance of the substring  
                        if(count==length2)
                        {
                            break;
                        }
                    }
                    k++;
               }
            
                if(count==length2)
                {
                    break;
                }
                // ^^ to get the first instance of the substring  
            }
        }

        if(count==length2)
        {
            printf("Substring is found starting starting from %d position\n",found);
        }
        else 
            printf("Substring not found\n");
    }
    
    else  
        printf("Substring too long\n");
}

int main() {

    char array[size],substring[size];
    
    printf("Input the string\n");
    fgets(array,sizeof(array),stdin);

    printf("Enter the substring to be searched for\n");
    fgets(substring,sizeof(substring),stdin);

    substring_func(array,substring);
    

    return 0;
}
