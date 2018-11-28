/* add new node in tail position of list */

void add_tail (NodeList *head,int v){
    NodeList cur=*head;
    NodeList new_val=malloc(sizeof(Node));
    new_val->value=v;
    new_val->next=NULL;
    if (*head==NULL)
        *head=new_val;
    else{
        while (cur->next != NULL){
            if (cur->next != NULL){
                cur=cur->next;}}
        cur->next=new_val;
    }
}
