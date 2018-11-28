#include <stdio.h>

void diff_abs (float *x ,float *y){
    float tmp1=*x;
    float tmp2=*y;
    *x=tmp1-tmp2;
    *y=tmp2-tmp1;
}

int main(){
    float a;
    float b;
    scanf("%f%f",&a,&b);
    diff_abs(&a,&b);
    printf("%.2f\n%.2f\n",a,b);
    return 0;
}

