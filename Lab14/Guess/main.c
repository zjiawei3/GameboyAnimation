#include "game.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	/* Declare variables for guess your number game */
	
	/* When this variable is 0 the player wants to quit */
	int keepPlaying = 1;
	
	int check_result;
	int guessed_number;
	
	while (keepPlaying)
	{
		switch(state)
		{
			case TITLE:
				title();
				break;
			case RANDOM_GEN:
				random_gen();
				break;
			case GUESS:
				guessed_number = guess();
				break;
			case CHECK:
				check_result = check(guessed_number);
				break;
			case REPORT:
				report(check_result);
				break;
			case PLAYAGAIN:
				keepPlaying = play_again();
				break;
			default:
				printf("should not happen!");
				return EXIT_FAILURE;
		}
	}
	
	return EXIT_SUCCESS;
}
