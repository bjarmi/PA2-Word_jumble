#include "List.h"

#ifndef PA2_SCRAMBLE_H
#define PA2_SCRAMBLE_H


class Scramble
{
private:
	int hints;
	int marked;
	List unscrambled_word;
	List scrambled_word;
	List hint_status;
	List guess;

	void display_status();

	void get_guess();

	void scramble_word();

public:
	explicit Scramble(List& word, int points);

	int start();

	void hint();

};


#endif //PA2_SCRAMBLE_H
