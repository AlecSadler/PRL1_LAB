#include <stdio.h>
#include <math.h>

float sum_pow (float n,float x)
{
    float exp;
    float pwtot=0;
    for (exp=0;exp<=n;exp++){
        pwtot=pwtot+pow(x,exp);}
    return pwtot;
}
int main(void)
{
    float a;
    float b;
    float res;
    scanf("%f%f",&a,&b);
    res=sum_pow(a,b);
    printf("%.2f",res);
    return 0;
}
    
    

    

        
        


