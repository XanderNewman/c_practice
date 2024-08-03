#include <stdio.h>

// NOTE: all possible response types
enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

// NOTE: data type
typedef struct {
	 char *name;
	enum response_type type;
} response;

// NOTE: I/O funcs
void dump(response r)
{
	 printf("Dear %s,\n", r.name);
	 puts("Unfortunately your last date contacted us to");
	 puts("say that they will not be seeing you again");
}

void second_chance(response r)
{
	 printf("Dear %s,\n", r.name);
	puts("Good news: your last date has asked us to");
	puts("arrange another meeting. Please call ASAP.");
}

void marriage(response r)
{
	printf("Dear %s,\n", r.name);
	puts("Congratulations! Your last date has contacted");
	puts("us with a proposal of marriage.");
}

// NOTE: Array of function pointers
void (*replies[])(response) = {dump, second_chance, marriage};

int main()
{
	// NOTE: array of elements of type response
	response r[] = {
	{"Mike", DUMP}, {"Luis", SECOND_CHANCE},
	{"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
	};
	
	// NOTE: iterates over the array and calls the corresponding 
	// func from the array of function pointers
	int i;
	for (i = 0; i < 4; i++) {
		(replies[r[i].type])(r[i]);
	}
	return 0;	
}
