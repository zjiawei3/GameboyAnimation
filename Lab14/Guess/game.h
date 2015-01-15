#ifndef GAME_H
#define GAME_H

enum
{
	TITLE,
	RANDOM_GEN,
	GUESS,
	CHECK,
	REPORT,
	PLAYAGAIN
};

void title(void);
void random_gen(void);
int guess(void);
int check(int);
int report(int);
int play_again(void);

#endif
