// delete the head node of a list if not NULL

void del_head (ListEl *head){
    ListEl tmp;
    if (*head!=NULL){
        if ((*head)->next==NULL){
            tmp=*head;
            *head=NULL;
            free(tmp);}
        else{
            tmp=*head;
            *head=(*head)->next;
            free(tmp);}}
}
