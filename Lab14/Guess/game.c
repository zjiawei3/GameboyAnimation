#include "game.h"

/* The current state we are in */
int state = 0;
int number = 0;

void title(void)
{
	printf("*************************************************************\n");
	printf("*                      Guess My Number                      *\n");
	printf("*************************************************************\n");
	state+=1;
}

void random_gen(void)
{
	/* Generate a random number here */
	number=rand();
	state+=1;
}

int guess(void)
{
	/* Prompt the user for an int */
	/* "Read" in an int here */
	/* Return the int */
	state+=1;
	return scan_nextInt();
}

int check(int guess)
{
	/* Compare the guess with the random number */
	/* Return -1 if lower 0 if win 1 if higher */
	state+=1;
	if(guess<number)return -1;
	if(guess>number)return 1;
	return 0;
}

int report(int result)
{
	/* Print out the appropriate message */
	/* Remember to go to the correct state afterward */
	if(result>0)printf("Your guess is higher");
	if(result<0)printf("Your guess is lower");
	if(result=0)printf("Your guess is right");
	state+=1;
	return result;
}

int play_again(void)
{
	/* Ask the user if he wants to play again */
	/* Ask for a character Y/N */
	/* Return 1 if the user wants to play again 0 if he wants to quit */
	state=0;
	printf("Play again?(Y/N)");
	if(scan_next()=='Y')return 1;
	return 0;
}
