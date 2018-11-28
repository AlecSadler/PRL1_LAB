#include <stdio.h>

#define rw_a 4
#define cl_a 2
#define rw_b 2
#define cl_b 3
#define rw_c rw_a
#define cl_c cl_b
void multiplymatr(int a[][cl_a],int b[][cl_b],int rwA,int clA,int rwB,int clB,int out[][cl_c]) {
    int i;
    int j;
    int h;
    int tmpMul[rwB];
    for(j=0;j<clB;j++) {
        for(i=0;i<rwB;i++) {
            tmpMul[i]=b[i][j];}
        for(i=0;i<rwA;i++) {
            out[i][j]=0;
            for(h=0;h<clA;h++) {
                out[i][j]+=a[i][h]*b[h][j];}
        }
    }
}
int main() {
    int i;
    int j;
    int mA[rw_a][cl_a];
    int mB[rw_b][cl_b];
    int mC[rw_c][cl_c];
    for(i=0;i<rw_a;i++) {
        for(j=0;j<cl_a;j++) {
            scanf("%d",&mA[i][j]);}
    }
    for(i=0;i<rw_b;i++) {
        for(j=0;j<cl_b;j++) {
            scanf("%d",&mB[i][j]);}
    }
    multiplymatr(mA,mB,rw_a,cl_a,rw_b,cl_b,mC);
    for(i=0;i<rw_c;i++) {
        for(j=0;j<cl_c;j++) {
            printf("%d ",mC[i][j]);}
        printf("\n");}
    return 0;
}







        




