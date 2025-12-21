#include <stdio.h>
int ack(int m,int n)
{
    int output;
    if (!m)
    {
        output=n+1;
        return output;
    }
    if(n==0&&m>0)
    {
        output=ack(m-1,1);
        return output;
    }
    if(m>0&&n>0)
    {
        output=ack(m-1,ack(m,n-1));
        return output;
    }

}

int main(){
    
    int m,n;
    printf("Input the value of: m and n \n");
    scanf("%d %d",&m, &n);

    printf("Value of A(%d,%d) is %d",m,n,ack(m,n));
    
    return 0;
}
