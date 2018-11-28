/* return list lenght */

int lenght (ListEl head){
  int len=0;
  if (head!=NULL)                      
    len=1+lenght(head->next);
  return len;
}
