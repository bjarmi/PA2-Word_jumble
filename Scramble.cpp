//
// Created by Sande on 11/02/2021.
//

#include <iostream>
#include "Scramble.h"
#include <cstring>

void Scramble::display_status()
{
	printf("Scrambled word:\n\t");
	for (auto i = 0; i < scrambled_word.size(); i++)
		std::cout << scrambled_word.get(i);
}

List Scramble::get_guess()
{
	List new_guess;

	printf("Hit me with your best shot!\n");
	std::cin.read(new_guess.payload, max_word_size);

	return new_guess;
}

Scramble::Scramble(List& word)
{
	for (auto i = 0; i < word.size(); i++)
		unscrambled_word.append(word.get(i));

	scrambled_word = scramble_word(word);
	guess = new List();
}

Scramble::~Scramble()
{
	delete[] guess;
}

void Scramble::start()
{
	do
	{
		display_status();
		std::memcpy(guess->payload, get_guess().payload, guess->size());
	}
	while (guess != &unscrambled_word);
}