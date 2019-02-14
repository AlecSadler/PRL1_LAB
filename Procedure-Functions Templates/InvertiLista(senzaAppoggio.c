//inverte una lista senza usarne una d'appoggio

void inverti_lista(Listadielementi* list){
	Listadielementi aux=*list;       
	Listadielementi aux2;
	*list=NULL;
	while (aux!=NULL){                  //finche' ci sono elementi nella lista R
		aux2=aux;                         //prendi il primo elemento di R,
		aux=aux->next;                    //sgancialo da R e
		aux2->next=*list;                 //mettilo in testa alla lista invertita.
		*list=aux2;}
}
