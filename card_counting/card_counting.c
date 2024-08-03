#include <stdio.h>
#include <stdlib.h>

int main() {
	char card_name[3];
	int val = 0;

	int count = 0;

	while (1){
	printf("Enter the card name: ");
	scanf("%2s", card_name);

        if (card_name[0] == 'K' || card_name[0] == 'Q' || card_name[0] == 'J') {
		val = 10;
	} else if (card_name[0] == 'A') {
		val = 11;
	} else if(card_name[0] == 'X'){
		break;
	} else if (atoi(card_name) < 3 || atoi(card_name) > 6){
		printf("Invalid card \n");
		continue;
	} else {
		val = atoi(card_name);
	}

	if (val >= 3 && val <= 6) {
		count++;
		printf("Count has gone up \n");
		printf("Current count %d\n", count);
	} else if (val == 10) {
		count--;
		printf("Count has gone down \n");
		printf("Current count %d\n", count);
	}
	}
	return 0;
}

