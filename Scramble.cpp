//
// Created by Sande on 11/02/2021.
//

#include <iostream>
#include "Scramble.h"
#include <cstring>
#include <algorithm>
#include <chrono>
#include <random>

void Scramble::display_status()
{
	printf("Scrambled word:\n\t");
	for (auto i = 0; i < scrambled_word->size(); ++i)
		std::cout << scrambled_word->get(i);
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

	unscrambled_word = new List();

	for (auto i = 0; i < word.size(); ++i)
		unscrambled_word->append(word.get(i));

	scrambled_word = new List();
	scramble_word();
	guess = new List();
}

Scramble::~Scramble()
{
	delete[] unscrambled_word;
	delete[] scrambled_word;
	delete[] guess;
}

void Scramble::start()
{
	do
	{
		display_status();
		std::memcpy(guess->payload, get_guess().payload, guess->size());
	}
	while (guess != unscrambled_word);
}

void Scramble::scramble_word()
{
	unsigned seed = std::chrono::system_clock::now()
			.time_since_epoch()
			.count();

	std::memcpy(
			scrambled_word->payload,
			unscrambled_word->payload,
			unscrambled_word->size()
	);

	shuffle(
			scrambled_word->payload[0],
			scrambled_word->payload[scrambled_word->size()],
			std::default_random_engine(seed)
	);

}