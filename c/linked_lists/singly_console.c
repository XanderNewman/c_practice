#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NOTE: we create a recursive struct 
typedef struct island {
	char *name;
	char *opens;
	char *closes;
	struct island *next;
} island;

// NOTE: takes a pointer to the first island and iterates printing each one
void display(island *start)
{
	island *i = start;
	for (; i != NULL ; i = i->next ) {
	printf("\nName: %s Open: %s-%s \n", i->name , i->opens ,  i->closes );
 }
}

// NOTE: it takes a string, allocates the space needed on the heap,
// sets name with a copy of the pointed value (strdup), 
// and sets the rest
island* create(char *name)
{
	island *i = malloc(sizeof(island));
	i->name = strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;

	return i;
}

// NOTE: it takes a pointer to the first island and frees 
// the allocated memory in each linked element
void release(island *start)
{
	island *i = start;
	island *next = NULL;

	for (; i != NULL; i = next) {
		next = i->next;
		free(i->name);
		free(i);
	}
}

int main(){
	island *start = NULL;
	island *i = NULL;
	island *next = NULL;
	char name[80];
	
	for(; fgets(name, 80, stdin) != NULL  ; i = next ) {
		next = create(name);
		if (start == NULL){
		start = next;
		}
		if (i != NULL){
		i->next = next;
		}
	}

	display(start);
	release(start);
}
