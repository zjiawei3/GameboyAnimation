#include "randlib.h"

int random_range(int min, int max)
{
	/* Generate a random number between min and max here */
	return (min+(rand()%(max-min)));
}

int random(int max)
{
	/* Generate a random number between 0 and max here */
	return (rand()%max);
}
