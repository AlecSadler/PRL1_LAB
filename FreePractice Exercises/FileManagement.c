/* il seguente codice è un esempio di come gestire dei files di testo come input/output, in questo caso abbiamo un file con
un elenco di nomi e cognomi, il programma ne legge il contenuto e mi restituisce solo i nomi, i file vanno creati prima
dell'esecuzione nella stessa cartella in cui abbiamo creato l'eseguibile */


#include <stdio.h>

#define RW 50

void main(){
  
  // dichiaro i puntatori ai due files uno di input e uno di output
  FILE *f;
  FILE *fout;
  
  // dichiaro la lunghezza massima della riga di testo che andrà a leggere
  char row[RW];
  
  // dichiaro le variabili che conterranno i nomi dei files input/output
  char file_name[RW];
  char file_nameout[RW];
  
  // queste variabili saranno le suddivisioni che desidero gestire in output
  char name[25];
  char surname[25];
  
  /* mi serve per controllare se in qualche riga manca una stringa o ce ne sono
  più di quelle che voglio */
  int check;
  
  // mi serve come controllo per vedere se ho ancora dati da leggere dall'input
  char *p;
  printf("Inserisci il nome del file da cui acquisire i dati1\n");
  scanf("%s",file_name);
  printf("inserisci il nome del file su cui stampare l'output\n");
  scanf("%s",file_nameout);
  
  // apre il file di input in lettura (r) posizionando il puntatore
  f=fopen(file_name,"r");
  
  // apre il dile di output in scrittura (w) posizionando il puntatore
  fout=fopen(file_nameout,"w");
  
  // controlla se l'apertura del file è andata a buon fine
  if (f==NULL){
    printf("ERROR:something gone wrong while opening file!");}
  
  // con un ciclo andiamo a lggere il contenuto finchè non c'è piu nulla
  while(!feof(f)){
    p=fgets(row,RW,f);
    if (p!=NULL){
      printf("%s\n",row);
      check=sscanf(row,"%s %s",name,surname);
      if (check!=2)
        printf("ERROR:wrong format of input file");
      
      // stampo nel file output la parte che mi interessa
      fprintf(fout,"%s\n",surname);}}
  
  // chiudo il file di input    
  fclose(f);
  }
