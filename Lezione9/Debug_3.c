#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 3
#define S 2

void multiply_matrices(int A[][S], int B[][M], int C[][M]){
    int i, j, k;
    
    for (i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            C[i][j]=0;
        }
    }
    
    for (i=0;i<N;i++) {
        // printf("i: %d\n", i);
        for(j=0;j<M;j++) {
            for (k=0;k<S;k++) {
                C[i][j]+=A[i][k]*B[k][j];
            }
            // printf("\tj: %d\n\t\t%d\t\t%d\n", j, C[i][0], C[i][1]);
        }
    }
}


int main() {
    int A[N][S], B[S][M], C[N][M];
    int i,j;
    
    for(i=0;i<N;i++){
        for(j=0;j<S;j++)
            scanf("%d\n", &(A[i][j]));
    }
    for(i=0;i<S;i++){
        for(j=0;j<M;j++) {
            scanf("%d\n", &(B[i][j]));
        }
    }
    multiply_matrices(A,B,C);
    for (i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%d ",C[i][j]);
        } printf("\n");
    }
    return 0;
}

