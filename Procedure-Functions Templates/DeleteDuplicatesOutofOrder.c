void delDupl(node *head){
  node *x=head;
  node *prev;
  node *cur;
  while (x!=NULL){
    cur=x->next;
    prev=x;
    while (cur!=NULL){
      if (cur->key==x->key){
        node *tmp=cur;
        prev->next=tmp->next;
        cur=cur->next;
        free(tmp);}
      else{
        prev=cur;
        cur=cur->next;}}
    x=x->next;}
}
