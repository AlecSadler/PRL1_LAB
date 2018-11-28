*/ print complete list */

void print_list (NodeList head){                   
    NodeList cur=head;
    while (cur != NULL){
            printf("%d\n",cur->value);
            cur=cur->next;}
}

/* recursive method */

void printlist_rec (ListEl head){
  if (head!=NULL){
    printf("%d -> ",head->value);    
    printlist_rec(head->next);}
}
