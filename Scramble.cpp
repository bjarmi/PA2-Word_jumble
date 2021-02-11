#include <iostream>
#include "Scramble.h"
#include <algorithm>
#include <chrono>
#include <random>

// Display the game's status.
void Scramble::display_status()
{
	std::cout << "Scrambled word: ";
	for (auto i = 0; i < scrambled_word->size(); ++i)
		std::cout << scrambled_word->get(i);
	std::cout << std::endl;
}

// Prompt the user for a guess.
void Scramble::get_guess()
{
	guess = new List();

	std::cout << "Hit me with your best shot!" << std::endl;
	std::cout << "Guess: ";
	std::cin >> guess->payload;
	std::cout << std::endl;
}

Scramble::Scramble(List& word)
{

	unscrambled_word = new List();
	scrambled_word = new List();

	for (auto i = 0; i < word.size(); ++i)
	{
		unscrambled_word->append(word.get(i));
		scrambled_word->append(word.get(i));
	}

	scramble_word();
}

Scramble::~Scramble()
{
	delete unscrambled_word;
	delete scrambled_word;
	delete guess;
}

// Start the guessing sequence.
void Scramble::start()
{
	while (guess != unscrambled_word)
	{
		display_status();

		// Todo.

		get_guess();
	}
}

// Scramble the word to be guessed.
void Scramble::scramble_word()
{
	unsigned seed = std::chrono::system_clock::now()
			.time_since_epoch()
			.count();

	shuffle(
			&scrambled_word->payload[0],
			&scrambled_word->payload[scrambled_word->size()],
			std::default_random_engine(seed)
	);
}