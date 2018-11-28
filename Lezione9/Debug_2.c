#include <stdio.h>
#include <stdlib.h>

//List structure:
struct elemento {
	float info;
	struct elemento *next;
};

typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;


ListaDiElementi readList();

ListaDiElementi deleteIfNextLarger(ListaDiElementi list);




//Function to print all the elements of the list:
void printList(ElementoDiLista *list) {
	printf("(");
	while (list != NULL) {
		printf("%.1f ", list->info);
		list = list->next;
	}
	printf(")\n");
}




int main() {
	ListaDiElementi list1, list2;

	//Read and print the list:
	list1 = readList();
	printf("List\n");
	printList(list1);

	//Deletes element out of order in the list
	list2 = deleteIfNextLarger(list1);

	//Print the cleaned list:
	printf("Deleted list:\n");
	printList(list2);

	return 0;
}




//Function to acquire a list of integers:
ListaDiElementi readList() {
	ListaDiElementi head = NULL;
	ListaDiElementi previous = NULL;
	ListaDiElementi item;
	float value=1;
		while(value != 0) {
     			scanf("%f", &value);
			if(value != 0) {
				//Create a new list item:
				item = (ListaDiElementi) malloc(sizeof(ElementoDiLista));
				item->info = value;
				item->next = NULL;
				if(previous == NULL) {	//Item is the first element:diobestia//
				head = item;
				previous=item;
				}
				else {
				//Item is not the first element:
				previous->next = item;
				previous = item;
				}
			}
		}
	return head;
	}

ListaDiElementi deleteIfNextLarger(ListaDiElementi list) {
	ListaDiElementi item = list, previous = NULL;
	int istail = item == NULL;
	while (!istail) {
		if (item->next != NULL) {
			if (item->info > item->next->info) {
				if (previous == NULL) {			//MOVE LIST HEAD
					list = item->next;
					free(item);
					item = list;
				}
				else {
					previous->next = item->next;
					free(item);
					item = previous->next;
				}
			}	
			else {
				previous = item;
				item = item->next;
			}
		}
		else {							 //TAIL
			if (item->info < 0) {
	       			if(previous == NULL) {
					list=NULL;
				}
				else { previous->next=NULL; }
				free(item);
			}
			istail = 1;
		}
	}
	return list;
}
