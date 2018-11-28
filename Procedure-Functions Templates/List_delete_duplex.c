/* delete repeated nodes in the list */

void del_duplex (NodeList head){
	NodeList tmp;
   	if (head == NULL || head->next == NULL)
        			return;
        if (head->value == (head->next)->value) {
      		tmp = head->next;
        		head->next = tmp->next;
          free(tmp);
          del_duplex(head);
    }
      else
        del_duplex(head->next);
}
