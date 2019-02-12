/* la funzione acquisisce da tastiera una sequenza di 0 e 1 nel frattempo ne tiene il conto, appena viene digitata una cifra
diversa, l'acquisizione termina e questa cifra viene memorizzata in un puntatore. ARR_LEN è una costante che determina la 
lunghezza massima della sequenza */


void readbinary(char arr[], int *len, int *reps){
    int a;
    int count;
    scanf("%d", &a);
    for(count=0;count<ARR_LEN && ( a==0 || a==1 );count++){
        arr[count]=a;
        scanf("%d", &a);
    }
    *reps=a;
    *len=count;
}
