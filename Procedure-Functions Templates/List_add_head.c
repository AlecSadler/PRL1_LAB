/* add a new node in head position of list */

void add_h (NodeList *head,int v){
    NodeList new_val=malloc(sizeof(Node));
    new_val->next=*head;
    new_val->value=v;
    *head=new_val;
}
