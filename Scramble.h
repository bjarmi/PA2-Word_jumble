#include "List.h"

#ifndef PA2_SCRAMBLE_H
#define PA2_SCRAMBLE_H


class Scramble
{
private:
	List unscrambled_word;
	List scrambled_word;
	List guess;

	void display_status();

	void get_guess() const;

	void scramble_word();

public:
	explicit Scramble(List& word);

	~Scramble();

	void start();

};


#endif //PA2_SCRAMBLE_H
