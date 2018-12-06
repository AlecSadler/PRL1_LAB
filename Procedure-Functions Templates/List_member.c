/* returns TRUE if the element "el" is contained in the list */

int member (NodeList head,int el){
    NodeList cur=head;
    int ok=0;
    while (cur != NULL && ok==0){
        if (cur->value==el){
            ok=1;}
        else
            cur=cur->next;}
    return ok;
