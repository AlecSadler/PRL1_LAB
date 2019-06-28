// cancella determinati nodi in base a una condizione (VERSIONE ITERATIVA)

void deleteSomeNode (node **head){
  if (*head!=NULL){
    node *x=*head;
    node *prev=NULL;
    node *fw=x->next;
    while (fw!=NULL){
      if (***CONDITION***){
        if (prev==NULL){
          node *tmp=x;
          *head=(*head)->next;
          x=*head;
          fw=x->next;
          free(tmp);}
        else{
          node *tmp=x;
          prev->next=tmp->next;
          x=fw;
          fw=fw->next;
          free(tmp);}}
      else{
        prev=x;
        x=fw;
        fw=fw->next;}}
    if (***CONDITION***){
      if (prev!=NULL)
        prev->next=NULL;
      else
        *head=NULL;
      free(x);}}
}
