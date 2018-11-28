/* sort new nodes in ascending sort while you add them */

void add_ordered (NodeList *head,int v){
    NodeList new_val=malloc(sizeof(Node));
    NodeList prev=NULL;
    NodeList cur=*head;
    new_val->value=v;
    while (cur != NULL && cur->value < v){
        prev=cur;
        cur=cur->next;}
    if (prev != NULL){
        prev->next=new_val;
        new_val->next=cur;}
    else{
        add_h(head,v);
    }
