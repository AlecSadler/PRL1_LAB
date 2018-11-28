#include <stdio.h>

int mcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    
    return a;
}

int mcm(int a, int b) {
    return (a*b)/mcd(a,b);
}

int main()
{
   int a, b;
    
    

    scanf("%d", &a);
    scanf("%d", &b);
        
   if (a != 0) {
            printf("%d\n", mcd(a,b));
            printf("%d\n" , mcm(a,b));
        }
   return 0;
}

