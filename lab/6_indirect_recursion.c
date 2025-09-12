#include <stdio.h>

//functions need to have protypes made at the beginning because they need to call each other and one cant call the other if it is defined below it

int f(int n);
int g(int n);

int f(int n)
{
    if(n<=0)
        return 1;
    
    else 
    {
        //final is declared so that we can print the value at the end of each function run
        int final=g(n-1)*f(n-2);
        printf("We are in f(n) and value of x is %d\n",final);
        return final;
    }
}

int g(int n)
{
    if(n<=0)
        return 0;
    
    else 
    {
        int final= f(n-2)*g(n-3);
        printf("We are in g(n) and value of x is %d\n",final);
        return final;
       
    }
}



int main() {

    int input;
    printf("Enter the value of n");
    scanf("%d",&input);

    int answer=g(input);
    printf("The final return value of f(%d) is %d",input,answer);

    return 0;
}
