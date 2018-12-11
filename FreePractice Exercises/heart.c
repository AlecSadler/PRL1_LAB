// Il seguente codice disegna un cuore nel terminale con i simboli * e .

#include <stdio.h>

#define ROWS 15
#define CLMN 20

void main (){
  char heart [ROWS][CLMN];
  int i=0;
  int j;
  for (j=0;j<CLMN;j++){
    if (j==3 || j==4 || j==5 || j==14 || j==15 || j==16)
      heart [0][j]= '*';
    else
      heart[0][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==2 || j==6 || j==13 || j==17)
      heart [1][j]= '*';
    else
      heart [1][j]= ' '; }
  for (j=0;j<CLMN;j++){
    if (j==1 || j==7 || j==8 || j==11 || j==12 || j==18)
      heart [2][j]= '*';
    else
      heart [2][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==0 || j==9 || j==10 || j==19)
      heart [3][j]= '*';
    else
      heart [3][j]=' ';}
  for (j=0;j<CLMN;j++){
    if (j==0 || j==19)
      heart [4][j]='*';
    else
      heart [4][j]=' ';}
  for (j=0;j<CLMN;j++){
    if (j==0 || j==19)
      heart [5][j]='*';
    else
      heart [5][j]=' ';}
  for (j=0;j<CLMN;j++){
    if (j==1 || j==18)
      heart [6][j]='*';
    else
      heart [6][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==2 || j==17)
      heart [7][j]='*';
    else
      heart [7][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==3 || j==16)
      heart [8][j]='*';
    else
      heart [8][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==4 || j==15)
      heart [9][j]='*';
    else
      heart [9][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==5 || j==14)
      heart [10][j]='*';
    else
      heart [10][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==6 || j==13)
      heart [11][j]='*';
    else
      heart [11][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==7 || j==12)
      heart [12][j]='*';
    else
      heart [12][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==8 || j==11)
      heart [13][j]='*';
    else
      heart [13][j]= ' ';}
  for (j=0;j<CLMN;j++){
    if (j==9 || j==10)
      heart [14][j]='*';
    else
      heart [14][j]= ' ';}
  while (i<ROWS){
    for (j=0;j<CLMN;j++){
      printf("%c",heart[i][j]);}
    printf("\n");
    i++;}
}
