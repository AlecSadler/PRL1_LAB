// add a new node after the selected position

void add_4 (ListEl head,int el){
  int i;
  if (lenght_REC(head) <= 4)
    add_tail(&head,el);               
  else{
    ListEl new=malloc(sizeof(Node));
    ListEl cur=head;
    new->value=el;
    ListEl tmp;
    for (i=0;i<3;i++){
      cur=cur->next;}
      tmp=cur->next;
      cur->next=new;
      new->next=tmp;}
}      
