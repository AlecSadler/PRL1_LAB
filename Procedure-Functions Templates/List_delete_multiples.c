// delete all muliple values of v parameter

void del_multiple (ListEl *head,int v){
  ListEl tmp;
  if (*head!=NULL){
    if (multiple((*head)->value,v)){
      tmp=*head;                        
      *head=tmp->next;
      free(tmp);
      del_multiple(&(*head),v);}
    else
       del_multiple(&(*head)->next,v);}
}
