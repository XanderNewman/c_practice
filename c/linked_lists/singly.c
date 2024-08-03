#include <stdio.h>

/* NOTE: creates a recursive struct, recursive because it has 
 * one of its own type inside,
 * it has a pointer to the next instance of itself */ 
typedef struct island {
	char *name;
	char *opens;
	char *closes;
	struct island *next;
} island;



/* NOTE: a function to display the whole tour,
 * takes a pointer to the first island
 * and travels to the next one until theres none */
void display(island *start)
{
	island *i = start;
	for (; i != NULL ; i = i->next ) {
	printf("Name: %s \nOpen: %s-%s \n", i->name , i->opens ,  i->closes );
 }
}

int main(){
	island amity = {"Amity", "09:00", "17:00", NULL};
	island craggy = {"Craggy", "09:00", "17:00", NULL};
	island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
	island shutter = {"Shutter", "09:00", "17:00", NULL};

	amity.next = &craggy;
	craggy.next = &isla_nublar;
	isla_nublar.next = &shutter;

	// NOTE: This is how you add an element in the middle
	island skull = {"Skull", "09:00", "17:00", NULL};
	isla_nublar.next = &skull;
	skull.next = &shutter;

	display(&amity);
}
