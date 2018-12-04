// delete first n elements from list

void drop_n (ListEl *head,int n){
  ListEl cur=*head;
  ListEl tmp;
  int i=0;
  if (*head!=NULL){                  
    while (i<n && (*head)!=NULL){
      tmp=*head;
      free(tmp);
      *head=(*head)->next;
      i++;}}
}
