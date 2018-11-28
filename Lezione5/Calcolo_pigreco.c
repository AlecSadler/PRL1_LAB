#include <stdio.h>

float approx_pi (int k){
    int i;
    float pi=0;
    for (i=1;i<=(2*k-1);i+=4){
        pi=pi+(float)4/i;
    }
    for (i=3;i<=(2*k-1);i+=4){
        pi=pi-(float)4/i;
    }
    return pi;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%.6f",approx_pi(n));
    return 0;
}
