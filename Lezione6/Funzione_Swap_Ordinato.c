#include <stdio.h>

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;}
void order_swap (int *a,int*b,int *c){
    if (*a>*b)
        swap(a,b);
    if (*b>*c)
        swap(b,c);
    if (*a>*b)
        swap(a,b);
    }
int main(){
    int x;
    int y;
    int z;
    scanf("%d%d%d",&x,&y,&z);
    order_swap(&x,&y,&z);
    printf("%d\n%d\n%d\n",x,y,z);
    return 0;
}

