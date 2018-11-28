#include <stdio.h>
#define ROWS 4
#define COLS 3
int check (int matrix[][COLS], int rows, int cols) {
    int i = 0;
    int j = cols-1;
    int found = -1;
    while(j >= 0 && found == -1) {
        int ok = 1;
        i = 0;
        while(i < rows && ok) {
            if(matrix[i][j]%3) {
                ok = 0;
            } else {
                i++;
            }
        }
        if (ok) {
            found = j;
        } else {
            j--;
        }
    }
    return found;
}
int main() {
    int i;
    int j;
    int index;
    int matrix[ROWS][COLS];
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    index=check(matrix, ROWS, COLS);
    printf("%d\n", index);
    return 0;
}






        




